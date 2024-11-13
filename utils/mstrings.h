#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>


char *slice(const char* s, const uint start, const uint end);
char *slice_delim(const char* s, const uint start, const char *delim);
char **split_str(char* s, const char *delim, int *k);
char **split_stric(char* s, const char *delim, char *ignored, int *k);
int find(const char* target, const char* text);
size_t count(const char* s, const char delim);




char *slice(const char* s, const uint start, const uint end){
  char *buffer = (char *)malloc(end - start);
  memcpy(buffer, s + start, end - start);
  buffer[end-start] = '\0';
  return buffer;
}

char *slice_delim(const char* s, const uint start, const char *delim){
  int index = find(delim, s + start);
  return slice(s, start, index + start + 1);
}

size_t count(const char* s, const char delim){
  size_t c = 0;
  for (size_t i = 0; s[i] != '\0'; i++) c += (s[i] == delim);
  return c;
}

int find(const char* target, const char* text){
  int len = strlen(text);
  int target_len = strlen(target);

  for (int i = 0; i < len - target_len+1; i++){
    if (!strcmp(target, slice(text, i, i+target_len))) return i;
  }
  return -1;
}

char **split_stric(char* s, const char *delim, char *ignored, int *k){
  char **args = (char**)malloc(sizeof(char*) * 100);
  char *token = strtok(strdup(s), delim);
  int i = 0;
  int ignored_count = 0;
  while(token != NULL){
    args[i] = token;
    token = strtok(NULL, delim);
    if (find(args[i], ignored) != -1) ignored_count++;
    if (ignored_count % 2) strcat(args[i], token);
    // printf("%s\n", args[i]);
    i++;
  }
  args[i] = NULL;
  *k = i;
  return args;
}


char **split_str(char* s, const char *delim, int *k){
  char **args = (char**)malloc(sizeof(char*) * 100);
  char *token = strtok(strdup(s), delim);
  int i = 0;
  while(token != NULL){
    args[i] = token;
    i++;
    token = strtok(NULL, delim);
  }
  args[i] = NULL;
  if (k) *k = i;
  return args;
}


