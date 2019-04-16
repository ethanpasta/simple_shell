#include "shell_head.h"

/**
 * remove_node_env - function removes a node with value [str] from
 * the environment list
 * @head: head of linked list
 * @str: string to find in one of the nodes
 *
 * Return: 1 on success, 0 otherwise
 */
int remove_node_env(list_t **head, char *str)
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

/**
 * remove_node - function removes the node at a certain index
 * @head: head of list
 * @index: index of the node to remove
 *
 * Return: 1 on success, 0 otherwise
 */
int remove_node(list_t **head, unsigned int index)
{
	list_t *tmp = *head, *before;
	unsigned int i;

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp->str);
		free(tmp);
		return (0);
	}
	for (i = 0; i < index - 1 && tmp; i++)
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	else if (tmp->next == NULL)
	{
		free(tmp->next->str);
		free(tmp->next);
		tmp->next = NULL;
		return (1);
	}
	else
	{
		before = tmp->next;
		tmp->next = tmp->next->next;
		free(before->str);
		free(before);
	}
	return (1);
}
