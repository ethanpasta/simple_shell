#include "shell_head.h"

/**
 * exit_shell - function exits the shell with/without an exit value
 * @build: built in info structure
 *
 * Return: none
 */
void exit_shell(built_info_t *build)
{
	int status = 1;
	char *bet = ": ", *line;

	/* check if exited with argument */
	if (build->args[1])
	{
		status = _atoi(build->args[1]);
		if (status == -1)
		{
			_puts(build->filename, 2);
			_puts(bet, 2);
			line = _itoa(build->line_num);
			_puts(line, 2);
			_puts(bet, 2);
			_puts("exit: ", 2);
			_puts("Illegal number: ", 2);
			_puts(build->args[1], 2);
			_puts("\n", 2);
			free(line);
			return;
		}
	}
	else
		status = build->last_return;
	free_list(build->env);
	free_array(build->env_s);
	free_array(build->args);
	free_list(build->args_l);
	exit(status);
}

/**
 * unset_env - function that removes the previous initiation of
 * a environmental varible
 * @build: built in info structure
 *
 * Return: none
 */
void unset_env(built_info_t *build)
{
	if (!build->args[1] || build->args[2] != NULL)
	{
		errno = EINVAL;
		perror(build->args[0]);
		return;
	}
	help_unsetenv(&build->env, build->args[1]);
	free_array(build->env_s);
	build->env_s = list_to_array(build->env);
}

/**
 * set_env - function intitializes a new environment variable,
 * or modifies an existing one
 * @build: built in info structure
 *
 * Return: none
 */
void set_env(built_info_t *build)
{
	if (!build->args[1] || !build->args[2] || build->args[3] != NULL)
	{
		errno = EINVAL;
		perror(build->args[0]);
		return;
	}
	help_setenv(&build->env, build->args[1], build->args[2]);
	free_array(build->env_s);
	build->env_s = list_to_array(build->env);
}

/**
 * print_env - function prints all environment variables and their values
 * @build: built in info structure
 *
 * Return: none
 */
void print_env(built_info_t *build)
{
	print_list(build->env);
}

/**
 * do_built_in - function executes built in commands
 * @a: array of built-ins
 * @in: built in info structure
 *
 * Return: 1 on success, 0 otherwise
 */
int do_built_in(built_t a[], built_info_t *in)
{
	int i;

	for (i = 0; a[i].built_in; i++)
	{
		if (_strcmp(a[i].built_in, in->args[0]))
		{
			a[i].f(in);
			return (1);
		}
	}
	return (0);
}
