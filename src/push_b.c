/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:05:11 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 18:32:43 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ret_bottom(t_game *game, int base)
{
	t_stack *tmp;

	tmp = game->a;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->value < base)
	{
		reverse_rotate(&game->a, &game->operations, "rra");
		tmp = game->a;
		while (tmp->next)
			tmp = tmp->next;
	}
}

static int		is_need_push(t_stack *stack, int base, int size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (i < size)
	{
		if (base > tmp->value)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void			push_rotate(t_game *game, int base, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (is_need_push(game->a, base, size - i))
		{
			if (game->a->value < base)
			{
				push(&game->a, &game->b, &game->operations, "pb");
				count++;
			}
			else
				rotate(&game->a, &game->operations, "ra");
			i++;
		}
		else
			break ;
	}
	push_block(game, count, 0);
}

void			push_b(t_game *game)
{
	int	size;
	int	base;

	size = stack_size(game->a);
	while (size > 3)
	{
		base = return_base(game->a, size);
		ret_bottom(game, base);
		push_rotate(game, base, size);
		size = stack_size(game->a);
	}
}
