#include "main.h"
/**
 * main - simpel shell.
 * @argc: number of args
 * @argv: pointer to array of string of arguments
 * Return: 0 always
*/
int main(int argc __attribute__((unused)), char *argv[])
{
	size_t len;
	char *line = NULL, *command;
	int nr, loop = 0, statu = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#omar/sfn$ ", 11);
		nr = getline(&line, &len, stdin);
		if (nr >= 0)
		{
			line[nr - 1] = '\0';
			command = ignore_spaces(line);
			if (!built_in(command, line, statu))
				statu = super_execute(command, argv[0]);
			free(line);
			line = NULL;
		}
		else
		{
			free(line);
			break;
		}
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
 * @command: command line
 * Return: args
 */
char **allocate_buffer(int num_args, char *command)
{
	char **args, *delimiter = " ", *args_use;
	int i = 0;

	args = malloc((num_args + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	args_use = strtok(command, delimiter);
	while (args_use != NULL)
	{
	args[i] = _strdup(args_use);
	args_use = strtok(NULL, delimiter);
	i++;
	}
	args[i] = NULL;
	return (args);
}
/**
 * special_free - free all memo
 * @args: pointe to pointer
 */
void special_free(char **args)
{
	int i = 0;

	if (args != NULL)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args[i]);
		free(args);
	}
}
