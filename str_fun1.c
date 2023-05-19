#include "main.h"
/**
 * our_strncmp - compare to strings by index
 * @f_str: first string
 * @s_str: second string
 * @n: the index
 * Return: 0 on success
 * on error 1 returns
*/
int our_strncmp(char *f_str, char *s_str, int n)
{
	int i = 0;

	while (i < n)
	{
	if (f_str[i] != s_str[i])
		return (1);
	i++;
	}
	return (0);
}
