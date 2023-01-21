#include "../push_swap/stacks.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	free(stack->values);
	free(stack);
	return (1);
}

int	test_new_stack_set_elements_correctly(void)
{
	t_stack	*stack;
	ssize_t	total_elements;

	total_elements = 10;
	stack = new_stack(total_elements);
	if (stack == NULL)
		return (1);
	if (stack->elements != total_elements)
		return (free_stack(stack));
	return (0);
}

int	test_new_stack_set_top_element_as_0(void)
{
	t_stack	*stack;

	stack = new_stack(1);
	if (stack == NULL)
		return (1);
	if (stack->top != 0)
		return (free_stack(stack));
	return (0);
}

int	test_new_stack_with_0_or_negative_elements_returns_null(void)
{
	t_stack	*stack;

	stack = new_stack(0);
	if (stack != NULL)
		return (free_stack(stack));
	stack = new_stack(-1);
	if (stack != NULL)
		return (free_stack(stack));
	return (0);
}

void	run_test(int (*function)(void), const char *function_name)
{
	int	result;

	result = function();
	if (result != 0)
	{
		dprintf(STDERR_FILENO, "%s: FAILED.\n", function_name);
		return;
	}
	dprintf(STDOUT_FILENO, "%s: SUCCESS.\n", function_name); }

#define RUN_TEST(function) (run_test(function, #function))

int main(int argc, char *argv[])
{
	RUN_TEST(test_new_stack_set_elements_correctly);
	RUN_TEST(test_new_stack_set_top_element_as_0);
	RUN_TEST(test_new_stack_with_0_or_negative_elements_returns_null);
	return (EXIT_SUCCESS);
}

