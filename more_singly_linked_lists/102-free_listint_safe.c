#include "lists.h"
#include <stdlib.h>

/**
 * addr_exists - checks if an address exists in the visited list
 * @visited: head of the visited address tracking list
 * @addr: address to look for
 *
 * Return: 1 if found, 0 otherwise
 */
static int addr_exists(addr_node_t *visited, const listint_t *addr)
{
	while (visited != NULL)
	{
		if (visited->addr == addr)
			return (1);
		visited = visited->next;
	}

	return (0);
}

/**
 * free_visited - frees the visited address tracking list
 * @visited: head of the visited address tracking list
 */
static void free_visited(addr_node_t *visited)
{
	addr_node_t *next;

	while (visited != NULL)
	{
		next = visited->next;
		free(visited);
		visited = next;
	}
}

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: pointer to pointer to the head of the list
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count;
	addr_node_t *visited;
	addr_node_t *tail;
	addr_node_t *new_node;
	listint_t *next;

	count = 0;
	visited = NULL;
	tail = NULL;

	while (*h != NULL)
	{
		if (addr_exists(visited, *h))
		{
			free_visited(visited);
			*h = NULL;
			return (count);
		}

		new_node = malloc(sizeof(addr_node_t));
		if (new_node == NULL)
			exit(98);

		new_node->addr = *h;
		new_node->next = NULL;

		if (visited == NULL)
		{
			visited = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}

		next = (*h)->next;
		free(*h);
		count++;
		*h = next;
	}

	free_visited(visited);
	*h = NULL;

	return (count);
}
