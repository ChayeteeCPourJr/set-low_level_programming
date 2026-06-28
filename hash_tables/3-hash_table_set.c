#include "hash_tables.h"

/**
 * make_node - allocates and fills a new hash node
 * @key: the key to duplicate into the node
 * @value_copy: the already-duplicated value to store
 *
 * Return: pointer to the new node, or NULL on failure
 */
static hash_node_t *make_node(const char *key, char *value_copy)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (NULL);
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (NULL);
	}
	new->value = value_copy;
	return (new);
}

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key, cannot be an empty string
 * @value: the value associated with the key, must be duplicated
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new, *tmp;
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
	new = make_node(key, value_copy);
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}
