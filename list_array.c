#include "shell_head.h"

/**
 * array_to_list - function converts an array of strings into a
 * a linked list
 * @arr: array of strings
 *
 * Return: pointer to head of list
 */
list_t *array_to_list(char **arr)
{
	int i;
	list_t *head = NULL;

	for (i = 0; arr[i]; i++)
	{
		if (!add_node(&head, arr[i]))
			return (NULL);
	}
	return (head);
}

/**
 * list_to_array - function converts linked list to an array of strings
 * @h: head of list
 *
 * Return: array of strings
 */
char **list_to_array(list_t *h)
{
	char **arr;
	size_t len;
	int i = 0;

	if (!h)
		return (NULL);
	len = list_len(h);
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	while (h)
	{
		arr[i] = _strdup(h->str);
		if (!arr[i])
		{
			while (i--)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		i++;
		h = h->next;
	}
	arr[i] = NULL;
	return (arr);
}
