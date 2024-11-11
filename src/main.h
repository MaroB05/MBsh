#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "../utils/fileio.h"
#include "../utils/mstrings.h"

ssize_t take_input(char** buffer, size_t* size, FILE* stream);
void process_input(char* buffer, size_t size, FILE* stream);
char **parse_args(char** dest, char* command);

