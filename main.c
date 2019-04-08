#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell_head.h"

/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of arguments
 * @env: environment variable
 *
 * Return: exit status
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused))**av, char **env)
{
	size_t line;
	int i;
	char *buffer;
	char **args;
	size_t buffer_size;
	pid_t child_p;
	built_t built_ins[] = {
		{"env", print_env},
		{"setenv", NULL},
		{"unsetenv", NULL},
		{"cd", NULL},
		{NULL, NULL}
	};

	signal(SIGINT, SIG_IGN);
	buffer_size = 32;
	buffer = malloc(sizeof(char) * buffer_size);
	line = 0;
	while (1)
	{
		line++;
		if (isatty(0))
			_puts(" ($) ");
		args = check_create_args(&buffer, &buffer_size);
		if (args)
		{
			child_p = fork();
			if (child_p == 0)
				child_proc(args, built_ins, env, av, line);
			else
			{
				for (i = 0; args[i]; i++)
					free(args[i]);
				free(args);
				wait(NULL);
			}
		}
	}
	return (0);
}
