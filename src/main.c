/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:45:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/09 11:57:46 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

static t_game	*create_game(void)
{
	t_game *game;

	if (!(game = (t_game*)malloc(sizeof(t_game))))
		return (NULL);
	game->a = NULL;
	game->b = NULL;
	game->a_remain = 0;
	game->a_bottom = 0;
	game->b_remain = 0;
	game->b_bottom = 0;
	game->block = NULL;
	return (game);
}

void print_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int main(int ac, char **av)
{
	t_game	*game;
	t_block	*block;

	if (ac > 1)
	{
		game = create_game();
		game->a = reader(ac, av);
		push_b(game);
		sort(game);
		ft_printf("stack a : ");
		print_stack(game->a);
		ft_printf("stack b : ");
		print_stack(game->b);
		block = game->block;
		while (block)
		{
			ft_printf("%d ", block->size);
			block = block->next;
		}
	}
	else
		ft_error();
	return (0);
}
