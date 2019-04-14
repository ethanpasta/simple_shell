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

	/* check if exited with argument */
	if (build->args[1])
		status = _atoi(build->args[1]);
	free_list(build->env);
	free_array(build->env_s);
	free_array(build->args);
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
		_puts("Error: Usage: unsetenv [VARIABLE]\n", 2);
		return;
	}
	if (remove_node(&build->env, build->args[1]) == 0)
	{
		_puts("Error: Environment variable ", 2);
		_puts(build->args[1], 2);
		_puts(" not found\n", 2);
		return;
	}
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
	char *str, *val;
	int len1, len2;

	if (!build->args[1] || !build->args[2])
        {
                _puts("Error: Usage: setenv [VARIABLE] [VALUE]\n", 2);
                return;
        }
	val = find_env_value(build->env_s, build->args[1]);
	if (val)
	{
		free(val);
		remove_node(&build->env, build->args[1]);
	}
	len1 = _strlen(build->args[1]);
	len2 = _strlen(build->args[2]);
	str = malloc(sizeof(char) * (len1 + len2 + 2));
	_memcpy(str, build->args[1], len1);
	_memcpy(str + len1, "=", 1);
	_memcpy(str + len1 + 1, build->args[2], len2 + 1);
	if (!add_node(&build->env, str))
	{
		free(str);
		_puts("Error: could not set environment variable\n", 2);
		return;
	}
	free(str);
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
