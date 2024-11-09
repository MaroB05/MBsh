#include "functions.h"

FILE *openFile(char* filename, char* mode, char* err_msg){
  FILE* f = fopen(filename, mode);

  if(!f){
    printf("%s", err_msg);
    return NULL;
  }
  return f;
}



//TODO: a function for getting the full line of a file

//String manipulation
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

size_t getchars(char* const buffer, const size_t n, FILE *f){
  size_t c = fread(buffer, 1, n, f);
  buffer[c-1] = '\0';
  return c;
}

size_t getlines(char * const buffer, const size_t n, FILE *f, size_t *const lines){
  size_t c = 0;
  size_t l = 0;
  for (; c < n-1; c++){
    buffer[c] = fgetc(f);
    if(buffer[c] == '\n') {
      l++;
    }
    else if (buffer[c] == EOF) return -1;
  }
  buffer[c] = '\0';
  if (lines) *lines += l-1;
  return c;
}


