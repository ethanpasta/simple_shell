#include "shell_head.h"

/**
 * set_env - function intitializes a new environment variable,
 * or modifies an existing one
 * @env: array containing all environment variables
 * @var: new variable new, or existing one
 * @val: new variable value
 *
 * Return: none
 */
void set_env(char **env, char *var, char *val)
{
	int i;
	char **env_var;

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
	env[i] = str_concat(env[i], val);
}

/**
 * print_env - function prints all environment variables and their values
 * @env: array containing all environment variables
 *
 * Return: none
 */
void print_env(__attribute__((unused))char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		_puts(env[i], 1);
		_puts("\n", 1);
	}
}

/**
 * do_built_in - function executes built in commands
 * @arg: array of arguments
 * @env: environment variable
 * @a: array of built-in structures
 *
 * Return: 1 on success, 0 otherwise
 */
int do_built_in(char *arg, char **env, built_t a[])
{
	int i;

	for (i = 0; a[i].f; i++)
	{
		if (_strcmp(a[i].built_in, arg))
		{
			a[i].f(env);
			return (1);
		}
	}
	return (0);
}
