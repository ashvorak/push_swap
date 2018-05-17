/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:04:57 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 18:24:51 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack, char ***operations, char *operation)
{
	int buf;

	if (stack && stack->next)
	{
		buf = stack->value;
		stack->value = stack->next->value;
		stack->next->value = buf;
	}
	if (operation)
		*operations = add_operation(*operations, operation);
}

void	push(t_stack **stack_from, t_stack **stack_to, char ***op, char *oper)
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
			*stack_to = tmp;
		}
		else
			*stack_to = new_stack(buf);
	}
	if (oper)
		*op = add_operation(*op, oper);
}

void	rotate(t_stack **stack, char ***operations, char *operation)
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
		buf->next = NULL;
	}
	if (operation)
		*operations = add_operation(*operations, operation);
}

void	reverse_rotate(t_stack **stack, char ***operations, char *operation)
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
		buf->next = *stack;
		*stack = buf;
	}
	if (operation)
		*operations = add_operation(*operations, operation);
}
