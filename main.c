#include <signal.h>
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
	int check;

	signal(SIGINT, SIG_IGN);
	buffer_size = 32;
	buffer = malloc(sizeof(char) * buffer_size);
	_puts("$shellfish$ ");
	check = getline(&buffer, &buffer_size, stdin);
	while (_strcmp(buffer, "exit\n") == 0)
	{
		if (check == -1)
			_puts("\n");
		real_size = _strlen(buffer);
		buffer[real_size - 1] = '\0';
		child_p = fork();
		if (child_p == 0)
		{
			if (execve(buffer, av, NULL) == -1)
			{
				perror(av[0]);
				free(buffer);
				return 0;
			}
		}
		else
			wait(NULL);
		_puts("$shellfish$ ");
                check = getline(&buffer, &buffer_size, stdin);
	}
	free(buffer);
	return 0;
}
