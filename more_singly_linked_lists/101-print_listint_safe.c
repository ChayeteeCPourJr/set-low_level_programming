#include "lists.h"
#include <stdlib.h>

/**
 * addr_seen - checks if address was already visited
 * @visited: head of visited address list
 * @addr: address to look up
 *
 * Return: 1 if seen, 0 otherwise
 */
static int addr_seen(addr_node_t *visited, const listint_t *addr)
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
 * free_addr_list - frees the visited address list
 * @visited: head of visited address list
 */
static void free_addr_list(addr_node_t *visited)
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
 * print_number - prints an integer using _putchar
 * @n: integer to print
 */
static void print_number(int n)
{
	unsigned int u;
	char buf[12];
	int i;

	i = 0;
	if (n < 0)
	{
		_putchar('-');
		u = (unsigned int)(-(n + 1)) + 1;
	}
	else
		u = (unsigned int)n;
	if (u == 0)
	{
		_putchar('0');
		return;
	}
	while (u > 0)
	{
		buf[i++] = '0' + (u % 10);
		u /= 10;
	}
	while (i > 0)
		_putchar(buf[--i]);
}

/**
 * add_to_visited - adds a node address to visited list
 * @visited: pointer to head of visited list
 * @tail: pointer to tail of visited list
 * @addr: address to record
 */
static void add_to_visited(addr_node_t **visited,
		addr_node_t **tail, const listint_t *addr)
{
	addr_node_t *node;

	node = malloc(sizeof(addr_node_t));
	if (node == NULL)
		exit(98);
	node->addr = addr;
	node->next = NULL;
	if (*visited == NULL)
	{
		*visited = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
}

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count;
	addr_node_t *visited;
	addr_node_t *tail;

	count = 0;
	visited = NULL;
	tail = NULL;
	while (head != NULL)
	{
		if (addr_seen(visited, head))
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			print_number(head->n);
			_putchar('\n');
			free_addr_list(visited);
			return (count);
		}
		add_to_visited(&visited, &tail, head);
		print_number(head->n);
		_putchar('\n');
		count++;
		head = head->next;
	}
	free_addr_list(visited);
	return (count);
}
