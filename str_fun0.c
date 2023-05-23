#include "main.h"
/**
 * _strlen - to know the len of string
 * @str: the pointer which point to an string
 * Return: len
*/
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}
/**
 * count_args - count argummants from command line
 * @line: cmd line
 * Return: num of args
 */
int count_args(char *line)
{
	int i = 0, srch_spc = 1, num_args = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && srch_spc == 1)
		{
			num_args++;
			srch_spc = 0;
		}
		if (line[i + 1] == ' ')
			srch_spc = 1;
		i++;
	}
	return (num_args);
}

/**
 * _strdup - duplicates a string to an other one
 * @str: the string
 * Return: buff
 */
char *_strdup(char *str)
{
	int len = 0, j = 0;
	char *buff;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
		len++;
	buff = malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	while (str[j] != '\0')
	{
		buff[j] = str[j];
		j++;
	}
	buff[j] = '\0';
	return (buff);
}

/**
 * _strcpy - copy the string to the other.
 * @src: The from string
 * @dest: The to string
 * Return: On success the to string.
*/
char *_strcpy(char *dest, char *src)
{
	int l = 0, i;

	while (src[l] != '\0')
		l++;
	for (i = 0; i <= l; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - concat string to other
 * @dest: The string to.
 * @src: The string from.
 * Return: On success the string.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;

	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		i++;
		src++;
	}
	*dest = '\0';
	dest -= i;
	return (dest);
}
