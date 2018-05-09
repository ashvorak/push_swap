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
	return (game);
}

int main(int ac, char **av)
{
	t_game	*game;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ac > 1)
	{
		game = create_game();
		game->a = reader(ac, av);
	}
	else
		ft_error();
	return (0);
}