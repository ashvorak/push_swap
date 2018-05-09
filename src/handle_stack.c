#include "../inc/push_swap.h"

void	del_stack_head(t_stack **stack)
{
	t_stack *tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
