#include "main.h"
/**
 * our_strncmp - compare to strings by index
 * @f_str: first string
 * @s_str: second string
 * @n: the index
 * Return: 0 on success
 * on error -1 returns
*/
int our_strncmp(char *f_str, char *s_str, int n)
{
	int i = 0;

	while (i < n)
	{
	if (f_str[i] != s_str[i])
		return (-1);
	i++;
	}
	return (0);
}
/**
 * get_built_in - get built in commands
 * @str: comands
 * Return: 0 if success
 */
int get_built_in(char *str)
{
	int i = -1;

	if (_strlen(str) == 4 && our_strncmp(str, "exit", 4) == 0)
		i = 0;
	else if (_strlen(str) == 3 && our_strncmp(str, "env", 3) == 0)
		i = 1;
	return (i);
}

