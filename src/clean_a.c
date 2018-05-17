/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:43:31 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 18:43:50 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	clean_a(t_game *game)
{
	int	i;
	int base;
	int size;

	i = 0;
	base = return_base(game->a, game->a_remain);
	game->b_remain = 0;
	size = game->a_remain;
	while (i < size)
	{
		if (game->a->value < base)
		{
			push(&game->a, &game->b, &game->operations, "pb");
			game->a_remain--;
			game->b_remain++;
		}
		else
		{
			rotate(&game->a, &game->operations, "ra");
			game->a_bottom++;
		}
		i++;
	}
}
