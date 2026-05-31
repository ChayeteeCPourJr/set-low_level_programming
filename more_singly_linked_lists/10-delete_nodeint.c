#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t list
 * @head: pointer to pointer to the head of the list
 * @index: index of the node to delete (starts at 0)
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *to_delete;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		to_delete = *head;
		*head = (*head)->next;
		free(to_delete);
		return (1);
	}

	current = *head;
	i = 0;

	while (current->next != NULL && i < index - 1)
	{
		current = current->next;
		i++;
	}

	if (current->next == NULL)
		return (-1);

	to_delete = current->next;
	current->next = to_delete->next;
	free(to_delete);

	return (1);
}
