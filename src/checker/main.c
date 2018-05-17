/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 19:35:53 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

void	print_stack(t_stack *stack)
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
/*
int		main(int ac, char **av)
{
	t_stack *a;
	char	*line;
	char	**operations;

	if (ac > 1)
	{
		operations = NULL;
		a = reader(ac, av);
		while (get_next_line(0, &line) > 0)
		{
			operations = add_operation(operations, line);
			ft_strdel(&line);
		}
		if (checker(a, operations))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_free_arr(operations);
	}
	else
		ft_error();
	return (0);
}
*/