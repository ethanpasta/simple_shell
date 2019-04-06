#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell_head.h"

int main(int __attribute__((unused)) ac, char **av, char **env)
{
	char *buffer;
	char **args;
	char *command;
	size_t buffer_size;
	size_t real_size;
	pid_t child_p;

	signal(SIGINT, SIG_IGN);
	buffer_size = 32;
	buffer = malloc(sizeof(char) * buffer_size);
	while (1)
	{
		_puts("$shellfish$ ");
		if (getline(&buffer, &buffer_size, stdin) == -1)
		{
			_puts("\n");
			break;
		}
		if (_strcmp(buffer, "exit\n") == 1)
			break;
		real_size = _strlen(buffer);
		buffer[real_size - 1] = '\0';
		args = strtow(buffer, ' ');
		command = check_file_withP(env, args[0]);
		child_p = fork();
		if (child_p == 0)
		{
			if (execve(command, args, NULL) == -1)
			{
				perror(av[0]);
				free(buffer);
				exit(99);
			}
		}
		else
			wait(NULL);
	}
	free(buffer);
	return 0;
}
