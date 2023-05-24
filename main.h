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

/*built in functions*/
int get_built_in(char *str);
int built_in(char *command, char *free_line, int process_status);
void puts_env(void);

/*memory fuctions*/
void special_free(char **args);
char **allocate_buffer(int num_args, char *command);

/*path functions*/
char *full_path(char *file_name);

/*command line and execution functions*/
char *ignore_spaces(char *old_line);
int super_execute(char *command_line, char *nameof);
int count_args(char *line);
char *look_for_comment(char *command_line);

/*string functions*/
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int our_strncmp(char *str1, char *str2, int n);

#endif /* MAIN_H */
