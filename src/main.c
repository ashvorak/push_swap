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
		tmp1 = game->a;
		while (tmp1)
		{
			ft_printf("%d ", tmp1->value);
			tmp1 = tmp1->next;
		}
		ft_printf("\n");
		swap(game->a);
		tmp1 = game->a;
		while (tmp1)
		{
			ft_printf("%d ", tmp1->value);
			tmp1 = tmp1->next;
		}
		ft_printf("\n");
		swap(game->a);
		tmp1 = game->a;
		while (tmp1)
		{
			ft_printf("%d ", tmp1->value);
			tmp1 = tmp1->next;
		}
		ft_printf("\n");
		push(&game->a, &game->b);
		push(&game->a, &game->b);
		push(&game->a, &game->b);
		push(&game->a, &game->b);
		tmp1 = game->a;
		while (tmp1->next)
		{
			ft_printf("%d ", tmp1->value);
			tmp1 = tmp1->next;
		}
		ft_printf("%d ", tmp1->value);
		ft_printf("\n");
		while (tmp1)
		{
			ft_printf("%d ", tmp1->value);
			tmp1 = tmp1->prev;
		}
		ft_printf("\n");
		tmp2 = game->b;
		while (tmp2->next)
		{
			ft_printf("%d ", tmp2->value);
			tmp2 = tmp2->next;
		}
		ft_printf("%d ", tmp2->value);
		ft_printf("\n");
		while (tmp2)
		{
			ft_printf("%d ", tmp2->value);
			tmp2 = tmp2->prev;
		}
		ft_printf("\n");
	}
	else
		ft_error();
	return (0);
}