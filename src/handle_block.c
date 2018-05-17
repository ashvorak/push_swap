/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:04:42 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 18:23:03 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	reverse_push_a(t_game *game, t_stack *tmp, t_block *block)
{
	int i;
	int	len;
	int base;

	i = 0;
	len = block->bottom;
	base = return_base(tmp, block->bottom);
	while (i < len)
	{
		reverse_rotate(&game->b, &game->operations, "rrb");
		if (game->b->value >= base)
		{
			push(&game->b, &game->a, &game->operations, "pa");
			game->a_remain++;
			block->bottom--;
		}
		else
			block->size++;
		i++;
	}
	block->bottom = 0;
}

void			handle_block(t_game *game, t_block *block)
{
	int		i;
	int		size;
	t_stack	*tmp;

	i = 0;
	while (i < block->size)
	{
		rotate(&game->b, &game->operations, "rb");
		block->bottom++;
		i++;
	}
	block->size = 0;
	tmp = game->b;
	size = stack_size(tmp);
	while (size != block->bottom)
	{
		tmp = tmp->next;
		size = stack_size(tmp);
	}
	reverse_push_a(game, tmp, block);
}
