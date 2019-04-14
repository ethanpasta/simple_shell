#include "shell_head.h"

/**
 * add_node - function adds a new node a list
 * @head: head of list
 * @str: string to put in new node
 *
 * Return: 1 on success, 0 otherwise
 */
int add_node(list_t **head, char *str)
{
	list_t *new;
	list_t *tmp = *head;

	new = malloc(sizeof(list_t));
	if (!new || !head || !str)
		return (0);
	new->str = _strdup(str);
	if (!new->str)
	{
		free(new);
		return (0);
	}
	new->len = _strlen(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (1);
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return (1);
}

/**
 * free_list - function frees an entire list
 * @head: head of linked list
 *
 * Return: none
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}

/**
 * list_len - functions finds and returns amount of nodes in a list
 * @h: head of list
 *
 * Return: count of nodes
 */
size_t list_len(list_t *h)
{
	size_t count = 0;

	if (!h)
		return (0);
	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * print_list - function prints a list
 * @h: head of linked list
 *
 * Return: none
 */
void print_list(list_t *h)
{
	while (h)
	{
		printf("%s\n", h->str);
		h = h->next;
	}
}
