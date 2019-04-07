#include "shell_head.h"

/**
 * print_env - function prints all environment variables and their values
 * @env: environment array containing all environment variables
 *
 * Return: none
 */

void print_env(__attribute__((unused))char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		_puts(env[i]);
		_puts("\n");
	}
}

/**
 * set_env - initializes an environment variable, or modifies an existing one
 * @env: environment variable
 *
 */

void set_env(__attribute__((unused))char** env)
{

}


/**
 *
 *
 *
 */

void unset_env(__attribute__((unused))char** env)
{

}

/**
 *
 *
 */

void change_dir(__attribute__((unused))char** env)
{

}

/**
 *
 *
 *
 */

int do_built_in(char *arg, char** env, built_t a[])
{
	int i;

	for (i = 0; a[i].f; i++)
	{
		if (_strcmp(a[i].built_in, arg))
		{
			a[i].f(env);
			return(1);
		}
	}
	return (0);
}
