#include "main.h"
/**
 * built_in - check for built_in command
 * @command: command to check
 * @free_line: line to free if is an exit command
 * @process_status: the status of the last process
 * Return: 1 on success
 * on fails 0 returned
*/
int built_in(char *command, char *free_line, int process_status)
{
	int check_for_built_in;

	check_for_built_in = get_built_in(command);
	if (check_for_built_in == 0)
	{
		free(free_line);
		exit(WEXITSTATUS(process_status));
	}
	else if (check_for_built_in == 1)
	{
		puts_env();
		return (1);
	}
	return (0);
}

/**
 * puts_env - print all the envirement variables
*/
void puts_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
