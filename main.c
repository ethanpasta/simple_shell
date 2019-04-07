#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell_head.h"

int main(int __attribute__((unused)) ac, char __attribute__((unused))**av, char **env)
{
	char *buffer;
	char **args;
	char *command;
	size_t buffer_size;
	size_t real_size;
	pid_t child_p;
	int i = 0;

	signal(SIGINT, SIG_IGN);
	buffer_size = 32;
	buffer = malloc(sizeof(char) * buffer_size);
	while (1)
	{
		if (isatty(0))
			_puts(" ($) ");
		if (getline(&buffer, &buffer_size, stdin) == -1)
		{
			_puts("\n");
			exit(98);
		}
		if (_strcmp(buffer, "exit\n"))
			exit(99);
		real_size = _strlen(buffer);
		buffer[real_size - 1] = '\0';
		args = strtow(buffer, ' ');
		if (args)
		{
			child_p = fork();
			if (child_p == 0)
			{
				command = check_file_withP(env, args[0]);
				if (command && execve(command, args, NULL) == -1)
				{
					perror(args[0]);
					free(buffer);
					exit(100);
				}
				if (execve(args[0], args, NULL) == -1)
				{
					perror(args[0]);
					free(buffer);
					exit(101);
				}
			}
			else
			{
				wait(NULL);
			}
		}
		i++;
	}
	free(buffer);
	return 0;
}
