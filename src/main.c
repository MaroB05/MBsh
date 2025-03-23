#include "commands.h"

int main(int argc, char* argv[]){
  
  size_t size = 100;
  char *buffer = malloc(size);
  FILE *stream = stdin;
  // char **args = (char **)malloc(sizeof(char*) * 100);
  char **args;
  int k;
  current_working_dir = (char *) malloc(path_size);
  update_cwd(&current_working_dir);
    
  for(int i = 0; i < argc; i++){
    if (argc > 1)
      stream = openFile(argv[++i], "r", "");
    take_input(&buffer, &size, stream);
    process_input(buffer, size, stream);

    parse_args(args, buffer);
    printf("buffer: %s\n", buffer);
    for (int j = 0; args[j]; j++)
      printf("%s ", args[j]);

    printf("\n");

    fclose(stream);
    i++;
    free(args);
  }
  free(buffer);
  return 0;
}


ssize_t take_input(char **buffer, size_t *size, FILE* stream){
  if(stream == stdin)
    printf("|MBsh|%s> ", current_working_dir);
  ssize_t c = getline(buffer, size, stream); //could lead to memory leaks TODO: implement a safe getline
  (*buffer)[c-1] = '\0';
  return c;
}

void process_input(char *buffer, size_t size, FILE* stream){
  ssize_t s = 0;
  pid_t pid;
  int cmd_num, ret_val;
  char* cmd = NULL;
  char** args = NULL;
  while(s != -1){
    cmd = strtok(strdup(buffer), " "); 
    args = parse_args(NULL, buffer);
    cmd_num = find_internal_cmd(cmd);
    if (cmd_num != -1){
      exec_internal_cmd(cmd_num, args);
    } else {
      exec_external_cmd(cmd, args);
    }
    s = take_input(&buffer, &size, stream);
  }
}

char **parse_args(char** dest, char *command){
  int k = 0;
  int c = 0;
  char **args = split_str(command, "\"", &k);
  char **temp = (char**)malloc(100 * sizeof(char*));
  char **t;

  for (int i = 0; args[i]; i++){
    t = split_str(args[i], " ", &k);
    memmove(temp+c, t, k * sizeof(char*));
    c += k;
    i++;
    if (args[i]){
      memmove(temp+c, args+i, sizeof(char*));
      c++;
    }
    free(t);
  }
  free(args);
  return temp;
}

int find_internal_cmd(char cmd[]){
  if (!cmd)
    return -1;
  for (int i = 0; terminal_commands[i].cmd_f != NULL; i++){
    if (!strcmp(terminal_commands[i].cmd, cmd))
      return i;
  }
  return -1;
}

void exec_internal_cmd(int cmd_num, char* args[]){
  terminal_commands[cmd_num].cmd_f(args);
}

void update_cwd(char** path_buffer){
  char* old_buff = *path_buffer;

  while(!getcwd(*path_buffer, path_size)){
    if (errno == ERANGE){
      path_size *= 2;
      *path_buffer = (char *) realloc(*path_buffer, path_size);
      if (old_buff != *path_buffer)
        free(old_buff);
    }
  }
}

void exec_external_cmd(char* cmd, char** args){
  int pid;
  pid = fork();
  if (pid == 0){
    execvp(cmd, args);
    perror("command failed");
    exit(-1);
  }
  else{
    wait(NULL);
  }
}
