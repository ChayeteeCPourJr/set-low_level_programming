# Doubly Linked Lists

A full implementation of a doubly linked list in C, including traversal, insertion, deletion, search, and utility functions. Also includes reverse-engineering exercises (crackme4 & crackme5) and a Project Euler solution.

## Files

| File | Prototype | Description |
|---|---|---|
| `lists.h` | — | Header file with `dlistint_t` struct and all prototypes |
| `0-print_dlistint.c` | `size_t print_dlistint(const dlistint_t *h)` | Prints all elements; returns node count |
| `1-dlistint_len.c` | `size_t dlistint_len(const dlistint_t *h)` | Returns number of nodes |
| `2-add_dnodeint.c` | `dlistint_t *add_dnodeint(dlistint_t **head, const int n)` | Adds node at the beginning |
| `3-add_dnodeint_end.c` | `dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)` | Adds node at the end |
| `4-free_dlistint.c` | `void free_dlistint(dlistint_t *head)` | Frees the entire list |
| `5-get_dnodeint.c` | `dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)` | Returns node at index |
| `6-sum_dlistint.c` | `int sum_dlistint(dlistint_t *head)` | Returns sum of all node values |
| `7-insert_dnodeint.c` | `dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)` | Inserts node at given index |
| `8-delete_dnodeint.c` | `int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)` | Deletes node at given index |
| `100-password` | — | Password for crackme4 (reverse-engineered Python 3.4 bytecode) |
| `102-result` | — | Largest palindrome from product of two 3-digit numbers |
| `103-keygen.c` | `int main(int argc, char *argv[])` | Keygen for crackme5 |

## Data Structure

```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o program
```

## Usage Examples

```c
dlistint_t *head = NULL;

add_dnodeint_end(&head, 1);
add_dnodeint_end(&head, 2);
add_dnodeint_end(&head, 3);

print_dlistint(head);                        /* 1, 2, 3        */
printf("%lu\n", dlistint_len(head));         /* 3              */
printf("%d\n", sum_dlistint(head));          /* 6              */

insert_dnodeint_at_index(&head, 1, 99);
print_dlistint(head);                        /* 1, 99, 2, 3    */

delete_dnodeint_at_index(&head, 1);
print_dlistint(head);                        /* 1, 2, 3        */

free_dlistint(head);
head = NULL;
```

## Crackme5 Keygen

```bash
# Compile
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 103-keygen.c -o keygen5

# Generate key for any username
./crackme5 julien `./keygen5 julien`
# → Congrats!
```

The keygen was produced by reverse-engineering the `crackme5` ELF binary using `objdump`. It reconstructs six helper functions (`f1`–`f6`) that derive each key character as an index into a 64-character lookup table embedded in the binary.

## Author
Chayetee.
