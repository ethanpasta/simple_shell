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
	size_t line = 0, buffer_size = 32;
	char *prompt = " :) ", *buffer, **args;
	pid_t child_p = 1;
	built_info_t in;
        built_t built_ins[] = {
                {"exit", exit_shell},
                {"env", print_env},
                {"setenv", set_env},
                {"unsetenv", unset_env},
                {NULL, NULL}
	};
	(void)ac;
        (void)av;
	signal(SIGINT, SIG_IGN);
        buffer = malloc(sizeof(char) * buffer_size);
	in.env = copy_env(env);
	in.env_s = list_to_array(in.env);
	while (1)
	{
		line++;
		if (isatty(0))
			_puts(prompt, 2);
		args = check_create_args(&buffer, &buffer_size);
		if (args)
		{
			in.args = args;
			child_proc(built_ins, av, line, &child_p, &in);
			if (child_p != 0)
			{
 				wait(NULL);
			}
		}
		free_array(args);
		args = NULL;
		in.args = NULL;
	}
	return (0);
}
