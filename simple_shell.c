#include "main.h"
/**
 * main - simpel shell task 1
 * Return: 0 always
*/
int main(void)
{
	size_t len;
	char *line, *command, *args[] = {NULL, NULL};
	int stat, nr, loop;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1 || loop == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		nr = getline(&line, &len, stdin);
		if (nr >= 0)
		{
			line[nr - 1] = '\0';
			pid = fork();
			if (pid == 0)
			{
				command = ignore_spaces(line);
				args[0] = command;
				execve(command, args, NULL);
				perror("./shell");
			}
			else if (pid > 0)
				waitpid(pid, &stat, 0);
			free(line);
			line = NULL;
		}
		else
			break;
		loop++;
		}
	return (0);
}

/**
 * ignore_spaces - ignore surrounded spaces in command
 * @old_line: command line
 * Return: command line after remove spaces
*/
char *ignore_spaces(char *old_line)
{
	char *end_line, *new_line = old_line;

	while (*new_line == ' ')
		new_line++;
	end_line = new_line + (_strlen(new_line) - 1);
	while (end_line > new_line && *end_line == ' ')
		end_line--;
	*(end_line + 1) = '\0';
	return (new_line);
}
