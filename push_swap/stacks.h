#ifndef STACKS_H
# define STACKS_H
#include <stdlib.h>

typedef struct s_stack t_stack;
typedef struct s_stack
{
	ssize_t	elements;
	ssize_t	top;
	int		*values;
}	t_stack;

#endif

