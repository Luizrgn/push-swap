#include "stacks.h"
#include <stdlib.h>

t_stack	*new_stack(ssize_t elements)
{
	t_stack	*stack;
	int		*values;

	stack = malloc(sizeof(*stack));
	values = malloc(sizeof(*values) * elements);
	if (stack == NULL || values == NULL)
	{
		free(stack);
		free(values);
		return (NULL);
	}
	stack->values = values;
	stack->top = 0;
	return (stack);
}

