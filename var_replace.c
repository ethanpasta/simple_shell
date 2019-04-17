#include "shell_head.h"

/**
 * var_replace - function handles variable replacements
 * @build: built in info structure
 *
 * Return: variable value
 */
void var_replace(built_info_t *build)
{
	char *var, *val, *itoa;

	if (!build->args[1] || build->args[1][0] != '$')
		return;
	var = build->args[1] + 1;
	if (*var == '$')
	{
		remove_node(&build->args_l, 1);
		itoa = _itoa(getpid());
		add_node(&build->args_l, itoa);
		free(itoa);
		free_array(build->args);
		build->args = list_to_array(build->args_l);
		return;
	}
	else if (*var == '?')
	{
		remove_node(&build->args_l, 1);
		itoa = _itoa(build->last_return);
		add_node(&build->args_l, itoa);
		free(itoa);
		free_array(build->args);
		build->args = list_to_array(build->args_l);
		return;
	}
	val = find_env_value(build->env_s, var);
	if (!val)
	{
		remove_node(&build->args_l, 1);
		free_array(build->args);
		build->args = list_to_array(build->args_l);
		return;
	}
	remove_node(&build->args_l, 1);
	add_node(&build->args_l, val);
	free_array(build->args);
	build->args = list_to_array(build->args_l);
	free(val);
}
