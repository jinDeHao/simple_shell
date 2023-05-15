#include "main.h"
/**
 * _strlen - to know the size of string
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
