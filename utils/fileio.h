#include <stdio.h>


FILE *openFile(char* filename, char* mode, char* err_msg);

size_t getchars(char* const buffer, const size_t n, FILE *f); 
size_t getlines(char * const buffer, const size_t n, FILE *f, size_t *const lines);



FILE *openFile(char* filename, char* mode, char* err_msg){
  FILE* f = fopen(filename, mode);

  if(!f){
    printf("%s", err_msg);
    return NULL;
  }
  return f;
}



size_t getchars(char* const buffer, const size_t n, FILE *f){
  size_t c = fread(buffer, 1, n-1, f);
  buffer[c] = '\0';
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
