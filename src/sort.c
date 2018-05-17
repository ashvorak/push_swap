/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:05:20 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 20:06:49 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		sort_3elem(t_stack **stack, char ***operations)
{
	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			if ((*stack)->next->next && \
			(*stack)->value > (*stack)->next->next->value)
			{
				rotate(&*stack, operations, "ra");
				if ((*stack)->value > (*stack)->next->value)
					swap(*stack, operations, "sa");
			}
			else
				swap(*stack, operations, "sa");
		}
		else
		{
			if ((*stack)->next->next && (*stack)->next->value > \
			(*stack)->next->next->value)
			{
				reverse_rotate(&*stack, operations, "rra");
				if ((*stack)->value > (*stack)->next->value)
					swap(*stack, operations, "sa");
			}
		}
	}
}

void		sort_3elem_top(t_stack **stack, char ***operations)
{
	if ((*stack)->value > (*stack)->next->value)
		swap(*stack, operations, "sa");
	if ((*stack)->next->next && \
	(*stack)->next->next->value < (*stack)->next->value)
	{
		rotate(&*stack, operations, "ra");
		swap(*stack, operations, "sa");
		reverse_rotate(&*stack, operations, "rra");
		if ((*stack)->next->value < (*stack)->value)
			swap(*stack, operations, "sa");
	}
}

static void	del_block_head(t_block **block)
{
	t_block *tmp;

	if (*block)
	{
		tmp = *block;
		*block = (*block)->next;
		free(tmp);
	}
}

static void	fix_stack_a(t_game *game)
{
	int i;

	i = 0;
	while (i < game->a_bottom)
	{
		reverse_rotate(&game->a, &game->operations, "rra");
		i++;
	}
	game->a_bottom = 0;
}

void		sort(t_game *game)
{
	int size;
	int base;

	(!is_sort(game->a)) ? sort_3elem(&game->a, &game->operations) : 0;
	while (stack_size(game->b))
	{
		size = game->block->size;
		base = return_base(game->b, size);
		(game->block->bottom) ? \
		handle_block(game, game->block) : push_a(game, base, size);
		(!game->block->size && \
		!game->block->bottom) ? del_block_head(&game->block) : 0;
		while (game->a_remain > 3)
		{
			fix_stack_a(game);
			clean_a(game);
			(game->b_remain) ? push_block(game, game->b_remain, 0) : 0;
		}
		fix_stack_a(game);
		game->a_remain = 0;
		game->b_remain = 0;
		!is_sort(game->a) ? sort_3elem_top(&game->a, &game->operations) : 0;
	}
}
