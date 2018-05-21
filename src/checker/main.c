/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/19 19:42:44 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

void			print_stack(t_stack *stack)
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

void			print_steps(t_stack *a, t_stack *b)
{
	ft_printf("a : ");
	print_stack(a);
	ft_printf("\n");
	ft_printf("b : ");
	print_stack(b);
	ft_printf("\n");
}

static t_bonus	*create_bonus(void)
{
	t_bonus	*bonus;

	if (!(bonus = (t_bonus*)malloc(sizeof(t_bonus))))
		return (NULL);
	bonus->num = 0;
	bonus->steps = 0; 
	return (bonus);
}

int				main(int ac, char **av)
{
	int		i;
	t_stack *a;
	t_bonus *bonus;
	char	*line;
	char	**operations;

	if (ac > 1)
	{
		bonus = create_bonus();
		operations = NULL;
		i = handle_flags(bonus, av);
		a = reader(ac, av, i);
		while (get_next_line(0, &line) > 0)
		{
			operations = add_operation(operations, line);
			ft_strdel(&line);
		}
		checker(a, operations, bonus) ? ft_printf("OK\n") : ft_printf("KO\n");
		ft_free_arr(operations);
	}
	else
		ft_error();
	return (0);
}
