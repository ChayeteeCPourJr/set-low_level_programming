#include "lists.h"
#include <stdlib.h>

/**
 * addr_seen - checks if an address has already been visited
 * @visited: head of the visited address list
 * @addr: address to look up
 *
 * Return: 1 if seen before, 0 otherwise
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
 * free_addr_list - frees the entire visited address list
 * @visited: head of the visited address list
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
	char digits[12];
	int i;

	if (n < 0)
	{
		_putchar('-');
		u = (unsigned int)(-(n + 1)) + 1;
	}
	else
		u = (unsigned int)n;

	i = 0;
	if (u == 0)
	{
		_putchar('0');
		return;
	}

	while (u > 0)
	{
		digits[i++] = '0' + (u % 10);
		u /= 10;
	}

	while (i > 0)
		_putchar(digits[--i]);
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
	addr_node_t *new_node;

	count = 0;
	visited = NULL;
	tail = NULL;

	while (head != NULL)
	{
		if (addr_seen(visited, head))
		{
			free_addr_list(visited);
			exit(98);
		}

		new_node = malloc(sizeof(addr_node_t));
		if (new_node == NULL)
			exit(98);

		new_node->addr = head;
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

		_putchar('[');
		print_number(head->n);
		_putchar(']');
		_putchar('\n');

		count++;
		head = head->next;
	}

	free_addr_list(visited);

	return (count);
}
