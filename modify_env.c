#include "shell_head.h"


void help_setenv(list_t **env, char *var, char *val)
{
	int len1, len2;
	char *str;

	remove_node(env, var);
        len1 = _strlen(var);
        len2 = _strlen(val);
        str = malloc(sizeof(char) * (len1 + len2 + 2));
        _memcpy(str, var, len1);
        _memcpy(str + len1, "=", 1);
        _memcpy(str + len1 + 1, val, len2 + 1);
        if (!add_node(env, str))
        {
                free(str);
                _puts("Error: could not set environment variable\n", 2);
                return;
        }
        free(str);
}

void help_unsetenv(list_t **env, char *var)
{
	if (remove_node(env, var) == 0)
        {
                _puts("Error: Environment variable ", 2);
                _puts(var, 2);
                _puts(" not found\n", 2);
                return;
        }
}
