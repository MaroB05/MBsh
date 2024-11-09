#include "main.h"

int main(int argc, char* argv[]){
  
  size_t size = 100;
  char *buffer = malloc(size);
  FILE *stream = stdin;

  for(int i = 0; i < argc; i++){
    if (argc > 1)
      stream = openFile(argv[++i], "r", "");
    take_input(&buffer, &size, stream);
    process_input(buffer, size, stream);

    fclose(stream);
    i++;
  }
  
  return 0;
}


