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
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	size_t line = 0, buffer_size = 32;
	int i;
	char *prompt = " :) ";
	char *buffer, **args;
	pid_t child_p;
	built_t built_ins[] = {
		{"env", print_env},
		{"setenv", NULL},
		{"unsetenv", NULL},
		{"cd", NULL},
		{NULL, NULL}
	};
	signal(SIGINT, SIG_IGN);
	buffer = malloc(sizeof(char) * buffer_size);
	while (1)
	{
		line++;
		if (isatty(0))
			_puts(prompt, 2);
		args = check_create_args(&buffer, &buffer_size);
		if (args)
		{
			child_p = fork();
			if (child_p == 0)
			{
				child_proc(args, built_ins, env, av, line);
			}
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
