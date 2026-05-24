# C - More Singly Linked Lists

A project focused on further implementation and manipulation of singly linked lists using integer nodes in C.

## Learning Objectives

- How to use linked lists
- How to implement various linked list operations
- How to handle edge cases (empty lists, invalid indices, NULL pointers)
- How to properly free memory and avoid memory leaks

## Requirements

### C Files
- Compiled on Ubuntu 20.04 LTS using `gcc -Wall -Wextra -Werror -pedantic`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file
- Only allowed C standard library functions: `malloc`, `free`, `exit`, `printf`

## Data Structure

```c
typedef struct listint_s
{
	int n;                    /* integer stored in the node */
	struct listint_s *next;   /* points to the next node   */
} listint_t;
```

## Files

| File | Prototype | Description |
|------|-----------|-------------|
| `0-print_listint.c` | `size_t print_listint(const listint_t *h)` | Prints all elements of a list |
| `1-listint_len.c` | `size_t listint_len(const listint_t *h)` | Returns number of elements in a list |
| `2-add_nodeint.c` | `listint_t *add_nodeint(listint_t **head, const int n)` | Adds a new node at the beginning |
| `3-add_nodeint_end.c` | `listint_t *add_nodeint_end(listint_t **head, const int n)` | Adds a new node at the end |
| `4-free_listint.c` | `void free_listint(listint_t *head)` | Frees a list |
| `5-free_listint2.c` | `void free_listint2(listint_t **head)` | Frees a list and sets head to NULL |
| `6-pop_listint.c` | `int pop_listint(listint_t **head)` | Deletes the head node and returns its data |
| `7-get_nodeint_at_index.c` | `listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)` | Returns the nth node |

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic <main_file.c> <function_file.c> -o <output>
```

### Examples
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-print_listint.c -o print_listint
gcc -Wall -Wextra -Werror -pedantic 6-main.c 6-pop_listint.c -o pop_listint
gcc -Wall -Wextra -Werror -pedantic 7-main.c 7-get_nodeint_at_index.c -o get_nodeint_at_index
```

## Author

* **[Chayetee]** - [GitHub] (https://github.com/ChayeteeCPourJr/set-low_level_programming.git)
