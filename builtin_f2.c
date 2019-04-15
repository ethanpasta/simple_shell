#include "shell_head.h"

/**
 * change_dir - function changes the current directory
 * @build: built in info structure
 *
 * Return: none
 */
void change_dir(built_info_t *build)
{
	char *newdir;
	char buff[1024];
	int which = 0;

	if (!build->args[1])
		newdir = find_env_value(build->env_s, "HOME");
	else if (_strcmp(build->args[1], "-") && build->args[2] == NULL)
	{
		newdir = find_env_value(build->env_s, "OLDPWD");
		which = 1;
	}
	else
		newdir = _strdup(build->args[1]);
	if (!newdir)
		return;
	getcwd(buff, 1024);
	if (chdir(newdir) == -1)
	{
		_puts("Error: could not change current directory to [", 2);
		_puts(newdir, 2);
		_puts("]\n", 2);
		free(newdir);
		return;
	}
	if (which)
	{
		_puts(newdir, 1);
		_puts("\n", 1);
	}
	help_setenv(&build->env, "OLDPWD", buff);
	help_setenv(&build->env, "PWD", newdir);
	free(newdir);
	free_array(build->env_s);
        build->env_s = list_to_array(build->env);
}
