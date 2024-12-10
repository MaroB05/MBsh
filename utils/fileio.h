#include <stdio.h>


FILE *openFile(const char filename[], const char mode[], char* err_msg);      // Opens a file with the path "filename" in mode "mode" and prints err_msg

size_t getchars(char buffer[], const size_t n, FILE stream[]);   // gets characters from a stream, untill it either fills the buffer or reaches EOF token in stream
size_t getlines(char buffer[], const size_t n, FILE stream[], size_t lines[]); // continuously loads lines from a stream, untill it either fills the buffer or reaches EOF 


FILE *openFile(const char filename[], const char mode[], char* err_msg){
  FILE* stream = fopen(filename, mode);

  if(!stream){
    if (!err_msg) err_msg = "Error opening file\n";
    perror(err_msg);
    return NULL;
  }
  return stream;
}


size_t getchars(char buffer[], const size_t n, FILE stream[]){
  size_t c = fread(buffer, 1, n-1, stream);
  buffer[c] = '\0';
  return c;
}

size_t getlines(char buffer[], const size_t n, FILE stream[], size_t lines[]){
  size_t c = 0;
  size_t l = 0;
  for (; c < n-1; c++){
    buffer[c] = fgetc(stream);
    if(buffer[c] == '\n') {
      l++;
    }
    else if (buffer[c] == EOF) return -1;
  }
  buffer[c] = '\0';
  if (lines) *lines += l-1;
  return c;
}
