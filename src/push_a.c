/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:05:06 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 18:27:07 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_need_push(t_stack *stack, int base, int size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (i < size)
	{
		if (base <= tmp->value)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void		push_a(t_game *game, int base, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_need_push(game->b, base, size - i))
		{
			if (game->b->value >= base)
			{
				push(&game->b, &game->a, &game->operations, "pa");
				game->a_remain++;
			}
			else
			{
				rotate(&game->b, &game->operations, "rb");
				game->block->bottom++;
			}
			game->block->size--;
			i++;
		}
		else
			return ;
	}
}
