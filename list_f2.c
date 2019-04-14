#include "shell_head.h"

/**
 * remove_node - function removes a node with value [str] from a list
 * @head: head of linked list
 * @str: string to find in one of the nodes
 *
 * Return: 1 on success (deletion), 0 otherwise
 */
int remove_node(list_t **head, char *str)
{
	list_t *tmp = *head, *before;
	char **var;

	if (!str || !head)
		return (0);
	var = strtow(tmp->str, '=');
	if (_strcmp(var[0], str))
	{
		*head = (*head)->next;
		free(tmp->str);
		free(tmp);
		free_array(var);
		return (1);
	}
	free_array(var);
	before = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		var = strtow(tmp->str, '=');
		if (_strcmp(var[0], str))
		{
			before->next = tmp->next;
			free(tmp->str);
			free(tmp);
			free_array(var);
			return (1);
		}
		free_array(var);
		var = NULL;
		before = tmp;
		tmp = tmp->next;
	}
	free_array(var);
	return (0);
}
