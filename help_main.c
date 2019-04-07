#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_head.h"

/**
 * check_create_args - function gets input from user, and checks if argument
 * is to exit, otherwise creates an array of arguments
 * @buffer: the buffer to use for getline
 * @buffer_size: size of the buffer
 *
 * Return: array of arguments
 */
char **check_create_args(char **buffer, size_t *buffer_size)
{
	size_t real_size;
	char **args;
	int exit_s = 1;

	if (getline(buffer, buffer_size, stdin) == -1)
	{
		_puts("\n");
		exit(98);
	}
	real_size = _strlen(*buffer);
	if (real_size == 1)
		return (NULL);
	(*buffer)[real_size - 1] = '\0';
	args = strtow(*buffer, ' ');
	if (_strcmp("exit", args[0]))
	{
		if (args[1])
			exit_s = _atoi(args[1]);
		exit(exit_s);
	}
	return (args);
}

/**
 * child_proc - function takes care of child process. Tries to
 * execute commands from the user
 * @args: array of arguments from user
 * @built_ins: array of built-in structure
 * @env: environment variable
 *
 * Return: none
 */
void child_proc(char **args, built_t built_ins[], char **env)
{
	char *command;

	/* check if command is a built in */
	if (do_built_in(args[0], env, built_ins) == 1)
		exit(102);
	/* check (and execute) if command is in PATH variable */
	command = check_file_withP(env, args[0]);
	if (command && execve(command, args, NULL) == -1)
	{
		perror(args[0]);
		exit(100);
	}
	/* check (and execute) if command on its own is a full command path */
	if (execve(args[0], args, NULL) == -1)
	{
		perror(args[0]);
		exit(101);
	}
}
