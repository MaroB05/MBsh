#include "main.h"
#include <string.h>


int main(int argc, char* argv[]){
  
  size_t size = 100;
  char *buffer = malloc(size);
  FILE *stream = stdin;
  char **args = (char **)malloc(sizeof(char*) * 100);
  int k;
    
  for(int i = 0; i < argc; i++){
    if (argc > 1)
      stream = openFile(argv[++i], "r", "");
    take_input(&buffer, &size, stream);
    process_input(buffer, size, stream);

    args = parse_args(buffer);
    printf("buffer: %s\n", buffer);
    for (int j = 0; args[j]; j++){
      printf("%s ", args[j]);
    }

    printf("\n");

    fclose(stream);
    i++;
  }
  return 0;
}



ssize_t take_input(char **buffer, size_t *size, FILE* stream){
  if(stream == stdin)
    printf("MBsh> ");
  ssize_t c = getline(buffer, size, stream);
  (*buffer)[c-1] = '\0';
  return c;
}

void process_input(char *buffer, size_t size, FILE* stream){
  ssize_t s = 0;
  pid_t pid;

  while(s != -1){
    pid = fork();
    if (pid == 0){
      char* p = strtok(strdup(buffer), " "); 
      execvp(p, parse_args(buffer));
      perror("command failed!\n");
    }
    else{
      wait(NULL);
    }
    s = take_input(&buffer, &size, stream);
  }
}

//TODO: check for the case of having spaces inside one argument ex: cat "my file"

char **parse_args(char *command){
  int k = 0;
  int c = 0;
  char **args = split_str(command, "\"", &k);
  char **temp = malloc(100 * sizeof(char*));

  for (int i = 0; args[i]; i++){
    char **t = split_str(args[i], " ", &k);
    memmove(temp+c, t, k * sizeof(char*));
    c += k;
    i++;
    if (args[i]){
      memmove(temp+c, args+i, sizeof(char*));
      c++;
    }
  }

  return temp;  
}

