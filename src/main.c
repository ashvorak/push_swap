/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:45:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 19:36:08 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	game->operations = NULL;
	game->block = NULL;
	return (game);
}

int				main(int ac, char **av)
{
	t_game	*game;

	if (ac > 1)
	{
		game = create_game();
		game->a = reader(ac, av);
		if (is_sort(game->a))
			return (0);
		push_b(game);
		sort(game);
		game->operations = convert_operations(game->operations);
		print_operations(game->operations);
		while (game->a)
			del_stack_head(&game->a);
		ft_free_arr(game->operations);
		free(game);
		game = NULL;
	}
	else
		ft_error();
	return (0);
}
