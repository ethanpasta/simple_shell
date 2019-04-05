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

/**
 * _strcmp - function compares between two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 1 if equal, 0 otherwise
 */
int _strcmp(char *str1, char *str2)
{
	if (!*str1 && !*str2)
		return (1);
	if (*str1 != *str2)
		return (0);
	return (_strcmp(str1 + 1, str2 + 1));
}
