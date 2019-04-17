#include "shell_head.h"

/**
 * check_digits - function checks if string contains only digits
 * @str: string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int check_digits(char *str)
{
	if (*str == '\0')
		return (1);
	if (*str >= '0' && *str <= '9')
		return (check_digits(str + 1));
	return (0);
}

/**
 * _atoi - function converts a string to an integer
 * @s: string to convert
 *
 * Return: Integer converted
 */
int _atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	if (check_digits(s) == 0)
		return (-1);
	while (s[i])
	{
		num = num * 10;
		num = num + (s[i] - '0');
		i++;
		if (num > INT_MAX)
		{
			printf("too big\n");
			return (-1);
		}
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

	if (num == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	tmp = num;
	while (tmp)
	{
		size++;
		tmp /= 10;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	while (num)
	{
		str[size--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
