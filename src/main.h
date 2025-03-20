#include "commands.h"

struct internal_command{
  const char* cmd;
  int (*cmd_f)(char**);
};


ssize_t take_input(char** buffer, size_t* size, FILE* stream);
void process_input(char* buffer, size_t size, FILE* stream);
char **parse_args(char** dest, char* command);
int find_internal_cmd(char cmd[]);
void internal_cmd(int cmd_num, char* args[]);
const struct internal_command terminal_commands[] = {
  {"cd", cd_},
  {"exit", exit_},
  {"", NULL},
};
