#include "main.h"
/**
 * super_execute - execute the file
 * @command_line: the file to execute
 * Return: the status of the last process
*/
int super_execute(char *command_line)
{
	pid_t pid;
	char **args = NULL, **env = environ, *path;
	int num_args, stat = 0;

	if (*command_line != '\0')
	{
		num_args = count_args(command_line);
		args = allocate_buffer(num_args, command_line);
		path = full_path(args[0]);
		if (path != NULL)
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
			perror(args[0]);
		special_free(args);
	}
	return (stat);
}

/**
 * full_path - give the full path
 * @file_name: the file to looking for
 * Return:a pointer the path of the file
*/
char *full_path(char *file_name)
{
	char right_path[BUFF_SIZE] = "/bin", *ptr_path;

	if (access(file_name, F_OK) == 0)
		return (file_name);
	_strcat(right_path, "/");
	ptr_path = _strcat(right_path, file_name);
	if (access(ptr_path, X_OK) == 0)
		return (ptr_path);
	return (NULL);
}
