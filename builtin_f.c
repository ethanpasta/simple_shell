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
 * un_set_env - function that removes the previous initiation of
 * a environmental varible
 * @build: the struct we use to stabilize our types
 *
 * Return: none
 */

void un_set_env(built_info_t build)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	if (!build.args[1])
	{
		_puts("Error: Usage: unsetenv [VARIABLE]\n", 2);
		return;
	}
	for(i = 0; build.env[i]; i++)
	{
		if(find_env_value(build.env, build.args[1]) != NULL)
		{
			flag = 1;
			for (j = i; build.env[j]; j++)
			{
				build.env[j] = build.env[j + 1];
			}
		}
	}
	if (flag == 0)
		_puts("Error: Environment variable not found\n", 2);
}

/**
 * set_env - function intitializes a new environment variable,
 * or modifies an existing one
 * @build: the struct we use to stabilize our types
 *
 * Return: none
 */
void set_env(built_info_t build)
{
	char *str;
	int len;

	if (!build.args[1] || !build.args[2])
        {
                _puts("Error: Usage: setenv [VARIABLE][VALUE]\n", 2);
                return;
        }
        un_set_env(build);

        str = malloc(sizeof(char) * (_strlen(build.args[1]) + _strlen(build.args[2]) + 2));
        if (!str)
                return;
	str = _strcpy(str, build.args[1]);
	str = str_concat(str, "=");
	str = str_concat(str, build.args[2]);
	for (len = 0; build.env[len]; len++)
		;
	build.env[len - 1] = str;
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
