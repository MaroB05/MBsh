#include "main.h"

char* current_working_dir;
int path_size = 100;

int cd_(char* args[]);
int exit_(char* args[]);


const struct internal_command terminal_commands[] = {
  {"cd", cd_},
  {"exit", exit_},
  {"", NULL},
};

int cd_(char* args[]){
  if (chdir(args[1]) == -1){
    perror("cd");
    return -1;
  }
  update_cwd(&current_working_dir);
  return 0;
}

int exit_(char* args[]){
  exit(0);
  return 0;
}
