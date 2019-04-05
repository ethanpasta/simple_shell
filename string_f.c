#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_head.h"

/**
 * _strlen - function returns length of string
 * @str: string to use
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (_strlen(str + 1) + 1);
}

/**
 * _puts - function prints buffer to standard output
 * @str: string to print
 *
 * Return: 1 on success, -1 on failure
 */
int _puts(char *buff)
{
	size_t len;

	len = _strlen(buff);
	if (write(1, buff, len) == -1)
		return (-1);
	return (1);
}
