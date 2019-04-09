#include "shell_head.h"

/**
 * exit_shell - function exits the shell with/without an exit value
 * @status: status to exit with
 *
 * Return: none
 */
void exit_shell(built_info_t build)
{
	int status = 1;

	if (build.args[1])
		status = _atoi(build.args[1]);
	exit(status);
}

/**
 * set_env - function intitializes a new environment variable,
 * or modifies an existing one
 * @env: array containing all environment variables
 * @var: new variable new, or existing one
 * @val: new variable value
 *
 * Return: none
 */
void set_env(built_info_t build)
{
	(void)build;
	/*int i;
	char **env_var;
	char **env = build.info.env;

	for (i = 0; env[i]; i++)
	{
		env_var = strtow(env[i], '=');
		if (_strcmp(env_var[0], var))
		{
			free(env[i]);
			env[i] = var;
			env[i] = str_concat(env[i], "=");
			env[i] = str_concat(env[i], val);
		}
	}
	env[i] = _realloc(env, i, (i + sizeof(char *)));
	if (!env[i])
		return;
	env[i] = var;
	env[i] = str_concat(env[i], "=");
	env[i] = str_concat(env[i], val);*/
}

/**
 * print_env - function prints all environment variables and their values
 * @env: array containing all environment variables
 *
 * Return: none
 */
void print_env(built_info_t build)
{
	int i;

	for (i = 0; build.env[i];i++)
	{
		_puts(build.env[i], 1);
		_puts("\n", 1);
	}
}

/**
 * do_built_in - function executes built in commands
 * @args: array of arguments
 * @env: environment variable
 * @a: array of built-in structures
 *
 * Return: 1 on success, 0 otherwise
 */
int do_built_in(char **args, char **env, built_t a[])
{
	(void)env;
	int i;

	for (i = 0; a[i].built_in; i++)
	{
		if (_strcmp(a[i].built_in, args[0]))
		{
			a[i].f(a[i].info);
			return (1);
		}
	}
	return (0);
}
