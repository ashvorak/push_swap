#include "../inc/push_swap.h"

void	swap(t_stack *stack)
{
	int buf;

	if (stack && stack->next)
	{
		buf = stack->value;
		stack->value = stack->next->value;
		stack->next->value = buf;
	}
}

void	push(t_stack **stack_from, t_stack **stack_to)
{
	int		buf;
	t_stack	*tmp;

	if (*stack_from)
	{
		buf = (*stack_from)->value;
		del_stack_head(&*stack_from);
		if (*stack_to)
		{
			tmp = new_stack(buf);
			tmp->next = *stack_to;
			(*stack_to)->prev = tmp;
			*stack_to = tmp;
		}
		else
			*stack_to = new_stack(buf);
	}
}

void	rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *buf;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		buf = *stack;
		while (tmp->next)
			tmp = tmp->next;
		*stack = (*stack)->next;
		tmp->next = buf;
		buf->prev = tmp;
		buf->next = NULL;
		(*stack)->prev = NULL;
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *buf;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		buf = tmp->next;
		tmp->next = NULL;
		buf->prev = NULL;
		buf->next = *stack;
		*stack = buf;
	}
}
