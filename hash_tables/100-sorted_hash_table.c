#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the array
 *
 * Return: a pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * make_snode - allocates and fills a new sorted hash node
 * @key: the key to duplicate into the node
 * @value_copy: the already-duplicated value to store
 *
 * Return: pointer to the new node, or NULL on failure
 */
static shash_node_t *make_snode(const char *key, char *value_copy)
{
	shash_node_t *new;

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (NULL);
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (NULL);
	}
	new->value = value_copy;
	new->next = NULL;
	new->sprev = NULL;
	new->snext = NULL;
	return (new);
}

/**
 * insert_sorted - inserts a node into the sorted (by key) list
 * @ht: the hash table whose shead/stail are updated
 * @new: the node to insert
 */
static void insert_sorted(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *tmp;

	tmp = ht->shead;
	while (tmp != NULL && strcmp(tmp->key, new->key) < 0)
		tmp = tmp->snext;

	if (tmp == NULL)
	{
		new->sprev = ht->stail;
		new->snext = NULL;
		if (ht->stail != NULL)
			ht->stail->snext = new;
		else
			ht->shead = new;
		ht->stail = new;
	}
	else
	{
		new->snext = tmp;
		new->sprev = tmp->sprev;
		if (tmp->sprev != NULL)
			tmp->sprev->snext = new;
		else
			ht->shead = new;
		tmp->sprev = new;
	}
}

/**
 * shash_table_set - adds or updates an element in a sorted hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key, cannot be an empty string
 * @value: the value associated with the key, must be duplicated
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new, *tmp;
	char *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->next;
	}
	new = make_snode(key, value_copy);
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->next = ht->array[index];
	ht->array[index] = new;
	insert_sorted(ht, new);
	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table to look into
 * @key: the key to look for
 *
 * Return: the value associated with key, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table in key order
 * @ht: the hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first;

	if (ht == NULL)
		return;
	first = 1;
	printf("{");
	tmp = ht->shead;
	while (tmp != NULL)
	{
		if (first == 0)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		first = 0;
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse key order
 * @ht: the hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first;

	if (ht == NULL)
		return;
	first = 1;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (first == 0)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		first = 0;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *next;

	if (ht == NULL)
		return;
	tmp = ht->shead;
	while (tmp != NULL)
	{
		next = tmp->snext;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = next;
	}
	free(ht->array);
	free(ht);
}
