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
  return chdir(args[1]);
}

int exit_(char* args[]){
  exit(0);
  return 0;
}
