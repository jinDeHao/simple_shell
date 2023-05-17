#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void special_free(char **args);
char **allocate_buffer(int num_args, char *command);
int count_args(char *line);
char *ignore_spaces(char *old_line);
int _strlen(char *str);
char *_strdup(char *str);

#endif
