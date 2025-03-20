#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "../utils/fileio.h"
#include "../utils/mstrings.h"

int cd_(char* args[]);
int exit_(char* args[]);


int cd_(char* args[]){
  if (chdir(args[1]) == -1){
    perror("cd");
    return -1;
  }
  return 0;
}

int exit_(char* args[]){
  exit(0);
  return 0;
}
