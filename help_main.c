#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_head.h"
#include <errno.h>

/**
 * error_msg - function writes message to standard error
 * @line_num: number of line on exit
 * @args: array of arguments
 * @av: array of arguments passed to file
 *
 * Return: none
 */
void error_msg(size_t line_num, char **args, char **av)
{
	char *buff = "";

	if (errno == ENOENT || errno == ENOTDIR)
	{
		buff = av[0];
		buff = str_concat(buff, ": ");
		buff = str_concat(buff, _itoa(line_num));
		buff = str_concat(buff, ": ");
		buff = str_concat(buff, args[0]);
		buff = str_concat(buff, ": ");
		buff = str_concat(buff, "not found");
		buff = str_concat(buff, "\n");
		_puts(buff, 2);
	}
	else
		perror(args[0]);

}

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

	if (getline(buffer, buffer_size, stdin) == -1)
	{
		if (isatty(0))
			_puts("\n", 1);
		exit(0);
	}
	real_size = _strlen(*buffer);
	if (real_size == 1)
		return (NULL);
	(*buffer)[real_size - 1] = '\0';
	args = strtow(*buffer, ' ');
	return (args);
}

/**
 * child_proc - function takes care of child process. Tries to
 * execute commands from the user
 * @args: array of arguments from user
 * @built_ins: array of built-in structure
 * @av: arguments to file
 * @line_num: current line number
 * @child_p: current process
 *
 * Return: none
 */
void child_proc(char **args, built_t built_ins[], char **av, size_t line_num, pid_t *child_p)
{
	char *command;
	char **env = built_ins[0].info->env;

	/* check if command is a built in, if it is, go back to main while loop */
	if (do_built_in(args, env, built_ins) == 1)
		return;
	*child_p = fork();
	if (*child_p != 0)
		return;
	/* check (and execute) if command is in PATH variable */
	command = check_file_withP(env, args[0]);
	if (command && execve(command, args, env) == -1)
	{
		error_msg(line_num, args, av);
		exit(100);
	}
	/* check (and execute) if command on its own is a full command path */
	if (execve(args[0], args, env) == -1)
	{
		error_msg(line_num, args, av);
		exit(101);
	}
}
