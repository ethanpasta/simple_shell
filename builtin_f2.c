#include "shell_head.h"

/**
 * change_dir_error - function to display error message for the cd command
 * @build: built in info structure
 *
 * Return: none
 */
void change_dir_error(built_info_t build)
{
	char *linenum, *bet = ": ";

	_puts(build.filename, 2);
	_puts(bet, 2);
	linenum = _itoa(build.line_num);
	_puts(linenum, 2);
	_puts(bet, 2);
	_puts("cd: ", 2);
	_puts("can't cd to ", 2);
	_puts(build.args[1], 2);
	_puts("\n", 2);
	free(linenum);
}

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

	/* if cd was entered with no arguments, go to home directory */
	if (!build->args[1])
		newdir = find_env_value(build->env_s, "HOME");
	else if (_strcmp(build->args[1], "-") && build->args[2] == NULL)
	{
		/* if cd was entered with '-', go to previous working directory */
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
		change_dir_error(*build);
		free(newdir);
		return;
	}
	if (which)
	{
		_puts(newdir, 1);
		_puts("\n", 1);
	}
	/* changes environment variable values once working directory was changed */
	help_setenv(&build->env, "OLDPWD", buff);
	help_setenv(&build->env, "PWD", newdir);
	free(newdir);
	free_array(build->env_s);
	build->env_s = list_to_array(build->env);
}
