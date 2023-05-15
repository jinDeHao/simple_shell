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

char *ignore_spaces(char *old_line);
int _strlen(char *str);

#endif
