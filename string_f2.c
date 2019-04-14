#include "shell_head.h"

/**
 * _strdup - function creates a copy of a string
 * @str: string to copy
 *
 * Return: newly allocated string
 */
char *_strdup(char *str)
{
	int len, i;
	char *newS;

	len = _strlen(str);
	newS = malloc(sizeof(char) * (len + 1));
	if (!newS)
		return (NULL);
	for (i = 0; str[i]; i++)
		newS[i] = str[i];
	newS[i] = '\0';
	return (newS);
}

/**
 * _memcpy - function copies memory area
 * @dest: destination pointer to copy to
 * @src: pointer to copy from
 * @n: amount of bytes to copy
 *
 * Return: a pointer to dest
 */
void _memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
}
