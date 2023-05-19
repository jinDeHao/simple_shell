#include "main.h"
/**
 * super_execute - execute the file
 * @command_line: the file to execute
*/
void super_execute(char *command_line)
{
	pid_t pid;
	char **args = NULL, *env[] = {NULL}, *path;
	int num_args, stat, idx = 0, j = 0;

	if (*command_line != '\0')
	{
		num_args = count_args(command_line);
		args = allocate_buffer(num_args, command_line);
		path = full_path(args[0]);
		if (our_strncmp(path, args[0], _strlen(args[0])) == 0)
			idx = 1;
		if ((*args[0] == '.' && *(args[0] + 1) == '/'))
			j = 1;
		if (idx == 0 || *args[0] == '/' || j == 1)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(path, args, env);
				perror(args[0]);
			}
			else if (pid > 0)
				waitpid(pid, &stat, 0);
			else
				perror("fork");
		}
		else
		{
			write(STDERR_FILENO, path, _strlen(path));
			write(STDERR_FILENO, ": command not found\n", 21);
		}
		special_free(args);
	}
}

/**
 * full_path - give the full path
 * @file_name: the file to looking for
 * Return:a pointer the path of the file
*/
char *full_path(char *file_name)
{
	char right_path[BUFF_SIZE] = "/bin", *ptr_path;

	_strcat(right_path, "/");
	ptr_path = _strcat(right_path, file_name);
	if (access(ptr_path, X_OK) == 0)
		return (ptr_path);
	return (file_name);
}
