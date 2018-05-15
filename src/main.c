/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:45:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/15 15:31:58 by oshvorak         ###   ########.fr       */
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
/*
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
*/

static void		print_operations(char **operations)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (operations[i])
	{
		if (operations[i] && operations[i + 1])
		{
			if ((!ft_strcmp(operations[i], "sa") && !ft_strcmp(operations[i + 1], "sb")) || \
        (!ft_strcmp(operations[i], "sb") && !ft_strcmp(operations[i + 1], "sa"))) {
				ft_printf("%s\n", "ss");
				num++;
				i++;
			} else if ((!ft_strcmp(operations[i], "ra") && !ft_strcmp(operations[i + 1], "rb")) || \
        (!ft_strcmp(operations[i], "rb") && !ft_strcmp(operations[i + 1], "ra"))) {
				ft_printf("%s\n", "rr");
				num++;
				i++;
			} else if ((!ft_strcmp(operations[i], "rra") && !ft_strcmp(operations[i + 1], "rrb")) || \
        (!ft_strcmp(operations[i], "rrb") && !ft_strcmp(operations[i + 1], "rra"))) {
				ft_printf("%s\n", "rrr");
				num++;
				i++;
			} else {
				ft_printf("%s\n", operations[i]);
				num++;
			}
		}
		else {
			ft_printf("%s\n", operations[i]);
			num++;
		}
		i++;
	}
	//ft_printf("num = %d\n", num);
}

int main(int ac, char **av)
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
		//ft_printf("stack a : ");
		//print_stack(game->a);
		//ft_printf("stack b : ");
		//print_stack(game->b);
		print_operations(game->operations);
	}
	else
		ft_error();
	return (0);
}
