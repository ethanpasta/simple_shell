#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell_head.h"

int main(int __attribute__((unused)) ac, char **av)
{
	char *buffer;
	size_t buffer_size;
	size_t real_size;
	pid_t child_p;

	buffer_size = 32;
	buffer = malloc(sizeof(char) * buffer_size);
	_puts("$shellfish$ ");
	while (getline(&buffer, &buffer_size, stdin) != -1)
	{
		real_size = _strlen(buffer);
		buffer[real_size - 1] = '\0';
		child_p = fork();
		if (child_p == 0)
		{
			if (execve(buffer, av, NULL) == -1)
			{
				perror(av[0]);
				return 0;
			}
		}
		else
		{
			wait(NULL);
		}
		_puts("$shellfish$ ");
	}
	return 0;
}
