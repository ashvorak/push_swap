#include "../inc/push_swap.h"

void	del_stack_head(t_stack **stack)
{
	t_stack *tmp;

	if (*stack)
	{
		tmp = *stack;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(tmp);
	}
}
