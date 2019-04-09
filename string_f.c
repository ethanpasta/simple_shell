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
	if (!str)
		return (-1);
	if (*str == '\0')
		return (0);
	return (_strlen(str + 1) + 1);
}

/**
 * _puts - function prints buffer to standard output
 * @buff: string to print
 * @stand: which standard to print to
 *
 * Return: 1 on success, -1 on failure
 */
int _puts(char *buff, int stand)
{
	size_t len;

	if (!buff)
		return (-1);
	len = _strlen(buff);
	if (write(stand, buff, len) == -1)
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
	if (!str1 || !str2)
		return (0);
	if (!*str1 && !*str2)
		return (1);
	if (*str1 != *str2)
		return (0);
	return (_strcmp(str1 + 1, str2 + 1));
}

/**
 * str_concat - function concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to a newly allocated space in memory which
 * contains the contents of s1, followed by s2
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, size1 = 0, size2 = 0, pos = 0;
	char *s;

	if (!s1 || !s2)
		return (NULL);
	size1 = _strlen(s1);
	size2 = _strlen(s2);
	s = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!s)
		return (NULL);
	while (i < size1)
		s[pos++] = s1[i++];
	while (j < size2)
		s[pos++] = s2[j++];
	s[pos] = '\0';
	return (s);
}
