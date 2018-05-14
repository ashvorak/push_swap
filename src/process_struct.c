#include "../inc/push_swap.h"

void	del_stack_head(t_stack **stack)
{
	t_stack *tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	del_block_head(t_block **block)
{
	t_block *tmp;

	if (*block)
	{
		tmp = *block;
		*block = (*block)->next;
		free(tmp);
	}
}
