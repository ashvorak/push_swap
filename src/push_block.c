/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:04:52 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 17:11:07 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_block		*new_block(int size, int bottom)
{
	t_block *block;

	if (!(block = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	block->size = size;
	block->bottom = bottom;
	block->next = NULL;
	return (block);
}

void		push_block(t_game *game, int count, int bottom)
{
	t_block	*tmp;

	if (game->block)
	{
		tmp = new_block(count, bottom);
		tmp->next = game->block;
		game->block = tmp;
	}
	else
		game->block = new_block(count, bottom);
}
