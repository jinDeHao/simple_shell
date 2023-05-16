#include "main.h"
/**
 * main - simpel shell task 1
 * Return: 0 always
*/
int main(void)
{
	size_t len;
	char *line, *command, **args;
	int stat, nr, loop, i = 1, num_args;
	pid_t pid;

	while (1)
	{
		args = NULL;
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
				num_args = count_args(command); 
				args = allocate_buffer(num_args);
				args[0] = strtok(command, " ");
				while (i < num_args)
				{
					args[i] = strtok(NULL, " ");
					i++;
				}
				args[i] = NULL;
				execve(args[0], args, NULL);
				perror("./shell");
			}
			eargs = allocate_buffer(num_args);lse if (pid > 0)
				waitpid(pid, &stat, 0);
			else
				perror("fork");
			free(line);
			line = NULL;
			free(args);
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
/**
 * allocate_buffer - allocate memory for args
 * @num_args: number of args
 * Return: args
 */
char **allocate_buffer(int num_args)
{
	char **args;

	args = malloc((num_args + 1) * sizeof(char *));
	if (!args)
		exit(1);
	return (args);
}

