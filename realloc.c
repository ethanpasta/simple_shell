#include "shell_head.h"

/**
 * _realloc - function reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: the old size of the memory block
 * @new_size: the size of the new memory block
 *
 * Return: pointer to new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i = 0;
	char *newptr, *tmp = ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(new_size));
	else if (new_size <= old_size)
		 return (ptr);
	newptr = malloc(new_size);
	if (!newptr)
		return (NULL);
	for (i = 0; i < old_size; i++)
		newptr[i] = tmp[i];
	free(ptr);
	return (newptr);
}
