#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_head.h"

char **check_create_args(char **buffer, size_t *buffer_size)
{
	size_t real_size;
	char **args;
	int exit_s = 1;

	if (getline(buffer, buffer_size, stdin) == -1)
	{
		_puts("\n");
		free(*buffer);
		exit(98);
	}
	real_size = _strlen(*buffer);
        (*buffer)[real_size - 1] = '\0';
        args = strtow(*buffer, ' ');
	if (_strcmp("exit", args[0]))
	{
		if (args[1])
			exit_s = _atoi(args[1]);
		free(*buffer);
		exit(exit_s);
	}
	return (args);
}

void child_proc(char **args, built_t built_ins[], char **env, char **buffer)
{
	int i;
	char *command;

	/* check if command is a built in */
	if (do_built_in(args[0], env, built_ins) == 1)
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
		free(*buffer);
		exit(102);
	}
	/* check (and execute) if command is in PATH variable */
	command = check_file_withP(env, args[0]);
	if (command && execve(command, args, NULL) == -1)
	{
		perror(args[0]);
		for (i = 0; args[i]; i++)
                        free(args[i]);
                free(args);
		free(command);
		free(*buffer);
		exit(100);
	}
	/* check (and execute) if command on its own is a full command path */
	if (execve(args[0], args, NULL) == -1)
	{
		perror(args[0]);
		for (i = 0; args[i]; i++)
                        free(args[i]);
                free(args);
		free(*buffer);
		exit(101);
	}
}
