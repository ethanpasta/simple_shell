#include "shell_head.h"

/**
 * free_array - function frees an array of strings
 * @arr: array to free
 *
 * Return: none
 */
void free_array(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

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
	char *line;

	/* check if one of two special error values, if it is create manual
	   error message */
	if (errno == ENOENT || errno == ENOTDIR)
	{
		buff = av[0];
		buff = str_concat(buff, ": ");
		line = _itoa(line_num);
		buff = str_concat(buff, line);
		free(line);
		buff = str_concat(buff, ": ");
		buff = str_concat(buff, args[0]);
		buff = str_concat(buff, ": ");
		buff = str_concat(buff, "not found");
		buff = str_concat(buff, "\n");
		/* print error message to standard error */
		_puts(buff, 2);
		free(buff);
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

	/* get input from user and store in buffer */
	if (getline(buffer, buffer_size, stdin) == -1)
	{
		/* if in interactive mode, print a new line */
		if (isatty(0))
		  _puts("\n", 1);
		/* exit if Ctrl + D was pressed */
		exit(0);
	}
	real_size = _strlen(*buffer);
	if (real_size == 1)
		return (NULL);
	/* Overwrite newline character (/n) with null character (/0) */
	(*buffer)[real_size - 1] = '\0';
	/* split buffer by spaces, into an array of strings */
	args = strtow(*buffer, ' ');
	free(*buffer);
	*buffer = NULL;
	return (args);
}

/**
 * child_proc - function takes care of child process. Tries to
 * execute commands from the user
 * @built_ins: array of built-in structure
 * @av: arguments to file
 * @line_num: current line number
 * @child_p: current process
 * @in: built in info structure
 *
 * Return: none
 */
void child_proc(built_t built_ins[], char **av, size_t line_num, pid_t *child_p, built_info_t *in)
{
	char *command;

	/* check if command is a built in, if it is, go back to main while loop */
	if (do_built_in(built_ins, in))
	{
		return;
	}
	*child_p = fork();
	if (*child_p != 0)
	{
		return;
	}
	/* check (and execute) if command is in PATH variable */
	command = check_file_withP(in->env_s, in->args[0]);
	if (command && execve(command, in->args, in->env_s) == -1)
	{
		error_msg(line_num, in->args, av);
		exit(0);
	}
	/* check (and execute) if command on its own is a full command path */
	if (execve(in->args[0], in->args, in->env_s) == -1)
	{
		error_msg(line_num, in->args, av);
		exit(0);
	}
}
