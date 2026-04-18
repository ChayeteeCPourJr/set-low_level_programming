# 0x0A. C - argc, argv

## Description

This project explores how to use command-line arguments in C programs through the `argc` and `argv` parameters of the `main` function. Programs are written in C following the Betty coding style and compiled on Ubuntu 20.04 LTS.

## Learning Objectives

- Understand how to use arguments passed to a program from the command line
- Understand the difference between `int main(void)` and `int main(int argc, char *argv[])`
- Know what `argc` and `argv` represent and how to use them

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Compiled on Ubuntu 20.04 LTS using `gcc` with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files end with a new line
- Code follows Betty style (`betty-style.pl` and `betty-doc.pl`)
- No global variables
- Maximum 5 functions per file
- No use of `printf`, `puts`, or similar — only `_putchar` for output
- All function prototypes are in `main.h`

## Files

| File | Description |
|------|-------------|
| `main.h` | Header file containing all function prototypes |
| `0-whatsmyname.c` | Prints the name of the program followed by a new line |
| `1-args.c` | Prints the number of arguments passed to the program |
| `2-args.c` | Prints all arguments received, one per line |
| `3-mul.c` | Multiplies two numbers passed as arguments |
| `4-add.c` | Adds positive numbers passed as arguments |

## Usage

Compile any file using:
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 <filename>.c -o <output>
```

### Examples

**0-whatsmyname.c** — prints the program's invocation name:
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-whatsmyname.c -o mynameis
$ ./mynameis
./mynameis
$ mv mynameis mynewnameis
$ ./mynewnameis
./mynewnameis
```

**1-args.c** — prints the number of arguments:
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-args.c -o nargs
$ ./nargs hello world
2
```

**2-args.c** — prints all arguments:
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-args.c -o args
$ ./args hello world
./args
hello
world
```

**3-mul.c** — multiplies two numbers:
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-mul.c -o mul
$ ./mul 245 3245342
795108790
$ ./mul
Error
```

**4-add.c** — adds positive numbers:
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-add.c -o add
$ ./add 1 10 100 1000
1111
$ ./add 1 2 3 e 4 5
Error
$ ./add
0
```

## Author

[Chayetee]
