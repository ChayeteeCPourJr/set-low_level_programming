#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the pointer of the head of the list
 * @idx: index where the new node should be inserted, starting from 0
 * @n: integer to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp;
	unsigned i;

	if (idx == 0)
		return (add_dnodeint(h, n));

	tmp = *h;
	for (i = 0; tmp != NULL; ++i)
	{
		if (i == idx -1)
		{
			if (tmp->next == NULL)
				return (add_dnodeint(h, n));

			new = malloc(sizeof(dlistint_t));
			if (new == NULL)
				return (NULL);

			new->n = n;
			new->next = tmp->next;
			new->prev = tmp;
			tmp->next->prev = new;
			tmp->next = new;

			return (new);
		}

		tmp = tmp->next;
	}

	return (NULL);
}
