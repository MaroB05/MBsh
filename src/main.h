#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "../utils/fileio.h"
#include "../utils/mstrings.h"

struct internal_command{
  const char* cmd;
  int (*cmd_f)(char**);
};


ssize_t take_input(char** buffer, size_t* size, FILE* stream);
void process_input(char* buffer, size_t size, FILE* stream);
char **parse_args(char** dest, char* command);
int find_internal_cmd(char cmd[]);
void exec_internal_cmd(int cmd_num, char* args[]);
const struct internal_command terminal_commands[] = {
  {"cd", cd_},
  {"exit", exit_},
  {"", NULL},
};
