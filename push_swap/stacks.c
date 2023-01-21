#include "stacks.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*new_stack(ssize_t elements)
{
	t_stack	*stack;
	int		*values;

	if (elements < 1)
		return (NULL);
	stack = malloc(sizeof(*stack));
	values = malloc(sizeof(*values) * elements);
	if (stack == NULL || values == NULL)
	{
		free(stack);
		free(values);
		return (NULL);
	}
	stack->values = values;
	stack->elements = elements;
	stack->top = 0;
	return (stack);
}

