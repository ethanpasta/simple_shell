#include "shell_head.h"

/**
 * _atoi - function converts a string to an integer
 * @s: string to convert
 *
 * Return: Integer converted
 */
int _atoi(char *s)
{
	int i = 0, num = 0;

	while (s[i] <= '9' && s[i] >= '0')
	{
		num = num * 10;
		num = num + (s[i] - '0');
		i++;
	}
	return (num);
}

/**
 * _itoa - function converts an integer to a string
 * @num: integer to convert
 *
 * Return: the integer in string format
 */
char *_itoa(size_t num)
{
	int tmp = num, size = 0;
	char *str;

	tmp = num;
	while (tmp)
	{
		size++;
		tmp /= 10;
	}
	str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	size--;
	while (num)
	{
		str[size--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
