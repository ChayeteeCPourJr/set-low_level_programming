# AI as Macro Safety Inspector and Conditional Code Generator

## Overview

This task demonstrates using AI to inspect and fix unsafe C preprocessor macros, and to generate robust conditional compilation scaffolding. The chosen scenario is **Scenario A** — an arithmetic macro: `MULTIPLY(a, b)`.

---

## Step 1: The Flawed Macro

**File:** `multiply_macro_flawed.h`

```c
#define MULTIPLY(a, b) a * b
```

This macro is intentionally unsafe. It has two critical bugs:

1. **No parentheses around parameters** — if an argument is an expression, operator precedence produces wrong results.
2. **No parentheses around the whole macro** — the result can be misread by surrounding expressions.

**Bug demonstration:**

```c
int x = MULTIPLY(2 + 3, 4);
/* Expands to: 2 + 3 * 4 = 14  (expected: 20) */

int y = 10 / MULTIPLY(2, 5);
/* Expands to: 10 / 2 * 5 = 25  (expected: 1) */
```

---

## Step 2: AI Safety Inspector

### Prompt sent to AI:

> "Act as a Senior C Developer and safety inspector. Review this C preprocessor macro for bug classes including operator precedence errors, missing parentheses, double evaluation side effects, and any other common macro pitfalls. Explain each issue clearly:
>
> `#define MULTIPLY(a, b) a * b`"

### AI Response (captured):

The AI identified the following issues:

**Bug 1 — Operator precedence on parameters:**
Without parentheses around `a` and `b`, any expression passed as an argument is not isolated. For example, `MULTIPLY(1 + 2, 3)` expands to `1 + 2 * 3 = 7` instead of the expected `9`. Fix: wrap each parameter — `(a)` and `(b)`.

**Bug 2 — Operator precedence on the whole expression:**
Without outer parentheses, the macro result can be split by surrounding operators. For example, `10 / MULTIPLY(2, 5)` expands to `10 / 2 * 5 = 25` instead of `1`. Fix: wrap the entire expansion in parentheses.

**Bug 3 — Side effects on double evaluation:**
If a macro argument has a side effect (e.g., `i++`), it may be evaluated more than once since macros perform textual substitution. For example, `MULTIPLY(i++, 2)` expands to `i++ * 2`, evaluating the increment once here — but in more complex macros with repeated use of the parameter, it would evaluate multiple times. The fix is to use an inline function for cases where side effects are a concern.

---

## Step 3: Safe Refactored Macro

**File:** `multiply_macro_safe.h`

```c
#define MULTIPLY(a, b) ((a) * (b))
```

All parameters and the full expression are wrapped in parentheses, neutralising the precedence bugs identified by the AI.

---

## Step 4: Conditional Code Generator

### Prompt sent to AI:

> "Act as a Senior C Developer. Generate robust conditional compilation scaffolding for a debug-mode `MULTIPLY` macro with the following three requirements:
> 1. When `DEBUG_MODE` is defined at compile time, the macro must print the operands and result to `stderr` using `fprintf`.
> 2. When `DEBUG_MODE` is not defined, the macro must silently evaluate to just the safe result with no output overhead.
> 3. The debug branch must use a `do { ... } while (0)` wrapper to make it safe for use in all statement contexts, including single-line `if` bodies without braces."

### AI Response (captured) — `debug_multiply.h`:

```c
#ifndef DEBUG_MULTIPLY_H
#define DEBUG_MULTIPLY_H

#include <stdio.h>

#define MULTIPLY(a, b) ((a) * (b))

#ifdef DEBUG_MODE
#define DEBUG_MULTIPLY(a, b) \
    do { \
        int _result = MULTIPLY((a), (b)); \
        fprintf(stderr, "[DEBUG] MULTIPLY(%d, %d) = %d\n", (a), (b), _result); \
    } while (0)
#else
#define DEBUG_MULTIPLY(a, b) MULTIPLY((a), (b))
#endif

#endif /* DEBUG_MULTIPLY_H */
```

**How to compile:**

```bash
# With debug output enabled:
gcc -DDEBUG_MODE -Wall -Werror -Wextra -pedantic -std=gnu89 main.c -o program

# Production (silent):
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c -o program
```

The three requirements are met:
- `#ifdef DEBUG_MODE` gates the verbose branch at compile time.
- The `#else` branch collapses cleanly to `MULTIPLY(a, b)` with zero overhead.
- `do { ... } while (0)` makes the multi-statement debug block safe in all statement positions.

---

## Step 5: Reflection

Using AI as a preprocessor safety inspector catches dangerous macro patterns instantly — bugs like missing parentheses are easy to overlook visually but cause silent, hard-to-trace arithmetic errors at runtime. The AI's ability to enumerate specific bug classes (precedence, side effects, statement safety) mirrors the mental checklist a senior developer applies, compressing hours of debugging experience into seconds. This is especially valuable in C, where the preprocessor operates entirely outside the type system and the compiler cannot warn about most macro-level logic errors.

---

## Files

| File | Description |
|------|-------------|
| `multiply_macro_flawed.h` | Initial unsafe macro — no parentheses |
| `multiply_macro_safe.h` | Refactored safe macro — fully parenthesised |
| `debug_multiply.h` | Conditional debug scaffolding with `DEBUG_MODE` support |
| `README.md` | Full task documentation |
