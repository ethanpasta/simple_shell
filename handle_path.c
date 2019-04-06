#include "shell_head.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *find_path(char **env)
{
	char **var_val, *var, *val;
	int i;

	for (i = 0; env[i]; i++)
	{
		var_val = strtow(env[i], '=');
		var = var_val[0];
		val = var_val[1];
		if (_strcmp(var, "PATH"))
			return (val);
	}
	return (NULL);
}

char *check_file_withP(char **env, char *command)
{
	struct stat st;
	char *build_path, *tmp, *str, **pa;
	int i;

	str = find_path(env);
	pa = strtow(str, ':');
	for (i = 0; pa[i]; i++)
	{
		tmp = str_concat(pa[i], "//");
		build_path = str_concat(tmp, command);
		if (stat(build_path, &st) == 0)
			return (build_path);
	}
	return ("none");
}
