#include "shell_head.h"

/**
 * word_count - function counts amount of words
 * seperated by space
 * @s: string to check
 * @del: delimiter to count words with
 *
 * Return: number of words
 */
int word_count(char *s, char del)
{
	int c = 0, i = 0;

	while (s[i])
	{
		if (s[i] != del)
		{
			c++;
			while (s[i] && s[i] != del)
				i++;
		}
		else
			i++;
	}
	return (c);
}

/**
 * strtow - function splits a string into words by delimeter
 * @str: string to split up
 * @del: delimiter to split string with
 *
 * Return: a pointer to an array of strings
 */
char **strtow(char *str, char del)
{
	char **a;
	int i = 0, j = 0, pos = 0, size = 0, words = 0, tmp;

	if (str == NULL || *str == '\0')
		return (NULL);
	/* finding the amount of words in the string */
	words = word_count(str, del);
	if (words == 0)
		return (NULL);
	/* malloc new space for array, with every element being a string */
	a = malloc(sizeof(char *) * (words + 1));
	if (!a)
		return (NULL);
	for (i = 0; i < words; i++)
	{
		size = 0;
		while (str[pos] == del)
			pos++;
		tmp = pos;
		while (str[pos] && str[pos++] != del)
			size++;
		a[i] = malloc(sizeof(char) * (size + 1));
		if (!a[i])
		{
			while (i--)
				free(a[i]);
			free(a);
			return (NULL);
		}
		/* for every word, copy on to current position in array */
		for (j = 0; j < size; j++)
		{
			a[i][j] = str[tmp];
			tmp++;
		}
		a[i][j] = '\0';
	}
	a[i] = NULL;
	return (a);
}
