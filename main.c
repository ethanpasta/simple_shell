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
	size_t buffer_size = 32;
	char *prompt = " :) ", *buffer;
	pid_t child_p = 1;
	int status = 0;
	built_info_t in;
	built_t built_ins[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", change_dir},
		{NULL, NULL}
	};
	(void)ac;
	signal(SIGINT, SIG_IGN);
	buffer = malloc(sizeof(char) * buffer_size);
	in.env = array_to_list(env);
	in.env_s = list_to_array(in.env);
	in.last_return = 0;
	in.line_num = 0;
	in.filename = av[0];
	while (1)
	{
		in.line_num++;
		if (isatty(0))
			_puts(prompt, 2);
		in.args = check_create_args(&buffer, &buffer_size);
		if (in.args)
		{
			in.args_l = array_to_list(in.args);
			child_proc(built_ins, &child_p, &in);
		}
		if (child_p != 0)
			wait(&status);
		if (WIFEXITED(status))
			in.last_return = WEXITSTATUS(status);
		free_array(in.args);
		free_list(in.args_l);
	}
	return (0);
}
