#include "shell_head.h"

/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of arguments
 * @env: environment variable
 *
 * Return: exit status
 */
int main(int ac, char **av, char **env)
{
	size_t line, buffer_size = 32, i;
	char *prompt = " :) ", *buffer, **args;
	pid_t child_p = 1;
	built_info_t *in;
	in = malloc(sizeof(built_info_t *));
	built_t built_ins[] = {
		{"exit", in, exit_shell},
		{"env", in, print_env},
		{"setenv", in, set_env},
		{"unsetenv", in, un_set_env},
		{NULL, in, NULL}};
	(void)ac;
	(void)av;
	signal(SIGINT, SIG_IGN);
	buffer = malloc(sizeof(char) * buffer_size);
	while (1)
	{
		line++;
		if (isatty(0))
			_puts(prompt, 2);
		args = check_create_args(&buffer, &buffer_size);
		if (args)
		{
			for (i = 0; built_ins[i].built_in; i++)
			{
				built_ins[i].info->args = args;
				built_ins[i].info->env = env;
			}
			child_proc(args, built_ins, av, line, &child_p);
			if (child_p != 0)
			{
				for (i = 0; args[i]; i++)
					free(args[i]);
				free(args);
				wait(NULL);
			}
		}
	}
	return (0);
}
