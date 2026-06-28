# Hash Tables

A C implementation of a hash table using the djb2 hashing algorithm and separate chaining (linked lists) for collision resolution.

## Files

| File | Prototype | Description |
|---|---|---|
| `hash_tables.h` | — | Header file with `hash_table_t`, `hash_node_t` structs and all prototypes |
| `hash_table_create.c` | `hash_table_t *hash_table_create(unsigned long int size)` | Creates a hash table of a given size |
| `1-djb2.c` | `unsigned long int hash_djb2(const unsigned char *str)` | Implements the djb2 hashing algorithm |
| `2-key_index.c` | `unsigned long int key_index(const unsigned char *key, unsigned long int size)` | Returns the array index for a given key |
| `3-hash_table_set.c` | `int hash_table_set(hash_table_t *ht, const char *key, const char *value)` | Adds or updates a key/value pair |
| `4-hash_table_get.c` | `char *hash_table_get(const hash_table_t *ht, const char *key)` | Retrieves the value associated with a key |
| `5-hash_table_print.c` | `void hash_table_print(const hash_table_t *ht)` | Prints all key/value pairs in array → list order |
| `6-hash_table_delete.c` | `void hash_table_delete(hash_table_t *ht)` | Frees the entire hash table |

## Data Structures

```c
/**
 * struct hash_node_s - node of a hash table
 * @key: the key, string
 * @value: the value corresponding to a key
 * @next: pointer to the next node of the list
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - hash table data structure
 * @size: the size of the array
 * @array: array of size @size, each cell points to a linked list
 *         used to handle collisions
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

## How It Works

1. **Hashing** — `hash_djb2` converts a key string into a large unsigned integer using the djb2 algorithm (seed `5381`, multiply by 33, add each character).
2. **Indexing** — `key_index` reduces that hash down to a valid array slot via `hash_djb2(key) % size`.
3. **Collision handling** — each array slot holds the head of a singly linked list. When two keys hash to the same index, the newer node is inserted at the **head** of that list.
4. **Updating** — if `hash_table_set` is called with a key that already exists, the existing node's value is freed and replaced rather than creating a duplicate node.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hash_table
```

## Usage Example

```c
hash_table_t *ht;

ht = hash_table_create(1024);
hash_table_set(ht, "c", "fun");
hash_table_set(ht, "python", "awesome");
hash_table_set(ht, "c", "isfun");        /* updates existing key */

printf("%s\n", hash_table_get(ht, "c")); /* isfun */

hash_table_print(ht);
/* {'python': 'awesome', 'c': 'isfun'} */

hash_table_delete(ht);
```

## Memory Safety

All functions have been verified with `valgrind --leak-check=full`:

```
==771== HEAP SUMMARY:
==771==     in use at exit: 0 bytes in 0 blocks
==771==   total heap usage: 25 allocs, 25 frees, 12,574 bytes allocated
==771== All heap blocks were freed -- no leaks are possible
==771== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Author

Low-level programming — hash tables project.
