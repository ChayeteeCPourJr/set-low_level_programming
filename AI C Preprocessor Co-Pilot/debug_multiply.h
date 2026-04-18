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
