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
# More Singly Linked Lists

## Description

This project is a continuation of the Singly Linked Lists project. It covers more advanced operations on singly linked lists in C, including safe traversal of looped lists, loop detection, and in-place reversal. All functions are written in C following the Betty coding style and compiled on Ubuntu 20.04 LTS.

## Learning Objectives

- How to use linked lists
- How to implement safe traversal of lists that may contain loops
- How to detect and find the start of a loop using Floyd's Cycle Detection Algorithm
- How to free memory safely including lists with loops
- How to insert and delete nodes at arbitrary positions

## Requirements

- All files compiled on Ubuntu 20.04 LTS
- Compiler: `gcc` with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the [Betty](https://github.com/alx-tools/Betty) style
- No global variables
- No more than 5 functions per file
- Only allowed C standard library functions: `malloc`, `free`, `exit`
- `_putchar` is used for output

## Data Structure

```c
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Files

| File | Prototype | Description |
|------|-----------|-------------|
| `2-add_nodeint.c` | `listint_t *add_nodeint(listint_t **head, const int n)` | Adds a new node at the beginning of a list |
| `6-sum_listint.c` | `int sum_listint(listint_t *head)` | Returns the sum of all data in a list |
| `9-insert_nodeint.c` | `listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)` | Inserts a new node at a given position |
| `10-delete_nodeint.c` | `int delete_nodeint_at_index(listint_t **head, unsigned int index)` | Deletes the node at a given index |
| `100-reverse_listint.c` | `listint_t *reverse_listint(listint_t **head)` | Reverses a linked list |
| `101-print_listint_safe.c` | `size_t print_listint_safe(const listint_t *head)` | Prints a list safely, handles loops |
| `102-free_listint_safe.c` | `size_t free_listint_safe(listint_t **h)` | Frees a list safely, handles loops |
| `103-find_loop.c` | `listint_t *find_listint_loop(listint_t *head)` | Finds the node where a loop starts |

## Function Details

### `add_nodeint`
Adds a new node at the beginning of a `listint_t` list. Returns the address of the new node, or `NULL` on failure.

### `sum_listint`
Returns the sum of all the `n` values in a `listint_t` list. Returns `0` if the list is empty.

### `insert_nodeint_at_index`
Inserts a new node at index `idx` (0-based). Returns the address of the new node, or `NULL` if the index is out of range or allocation fails.

### `delete_nodeint_at_index`
Deletes the node at index `index` (0-based). Returns `1` on success, `-1` on failure.

### `reverse_listint`
Reverses a `listint_t` list in place using only 1 loop and 2 variables. No `malloc`, `free`, or arrays used.

### `print_listint_safe`
Prints a `listint_t` list safely — works even if the list contains a loop. Exits with status `98` on failure. Traverses the list only once.

### `free_listint_safe`
Frees a `listint_t` list safely — works even if the list contains a loop. Sets `*head` to `NULL` after freeing. Returns the number of nodes freed. Traverses the list only once.

### `find_listint_loop`
Finds the node where a loop starts using **Floyd's Cycle Detection Algorithm** (tortoise and hare). Uses only 2 variables and no `malloc`, `free`, or arrays. Returns the address of the loop start node, or `NULL` if there is no loop.

## Floyd's Cycle Detection Algorithm

`find_listint_loop` works in two phases:

**Phase 1 — Detect the loop:**
- `slow` pointer moves one step at a time
- `fast` pointer moves two steps at a time
- If they meet, a loop exists

**Phase 2 — Find the loop start:**
- Reset `slow` to `head`, keep `fast` at the meeting point
- Move both one step at a time
- Where they meet is the start of the loop

## Compilation

```bash
# Example for task 103
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 \
    103-main.c 2-add_nodeint.c 103-find_loop.c \
    101-print_listint_safe.c 102-free_listint_safe.c \
    _putchar.c -o m && ./m
```

> `_putchar.c` is required for local compilation but should not be pushed to the repo. The grading system provides it automatic
## Author

* **[Chayetee]** - [GitHub] (https://github.com/ChayeteeCPourJr/set-low_level_programming.git)
