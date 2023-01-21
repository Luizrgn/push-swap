#ifndef STACKS_H
# define STACKS_H
#include <unistd.h>

typedef struct s_stack t_stack;
typedef struct s_stack
{
	ssize_t	elements;
	ssize_t	top;
	int		*values;
}	t_stack;

t_stack	*new_stack(ssize_t elements);

#endif

