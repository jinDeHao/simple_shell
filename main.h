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

#define BUFF_SIZE 1024
extern char **environ;

int get_built_in(char *str);
void special_free(char **args);
char **allocate_buffer(int num_args, char *command);
int count_args(char *line);
char *ignore_spaces(char *old_line);
int _strlen(char *str);
char *_strdup(char *str);
void super_execute(char *command_line);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int our_strncmp(char *str1, char *str2, int n);
char *full_path(char *file_name);

#endif
