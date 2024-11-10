#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "../utils/functions.h"

ssize_t take_input(char **buffer, size_t *size, FILE* stream);
void process_input(char *buffer, size_t size, FILE* stream);
char **parse_args(char *command);

