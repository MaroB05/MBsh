#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "../utils/functions.h"

ssize_t take_input(char **buffer, size_t *size, FILE* stream);
void process_input(char *buffer, size_t size, FILE* stream);


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
      execlp(p, p, NULL);
      perror("command failed!\n");
    }
    else{
      wait(NULL);
    }
    s = take_input(&buffer, &size, stream);
  }
}
