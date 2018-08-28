/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 16:45:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

void			free_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		(a) ? del_stack_head(&a) : 0;
		(b) ? del_stack_head(&b) : 0;
	}
}

void			print_stack(t_stack *stack, int is_color)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		(is_color) ? ft_printf("{green}%d{eoc} ", tmp->value)  \
		: ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
}

void			print_steps(t_stack *a, t_stack *b, t_bonus *bonus, char *str)
{
	(bonus->color) ? ft_printf("\n{seawave}//////////////////////////////\
	{eoc}\n") : ft_printf("\n//////////////////////////////\n");
	if (bonus->operation)
		(bonus->color) ? ft_printf("{red}%s{eoc}\n", str) \
		: ft_printf("%s\n", str);
	(bonus->color) ? ft_printf("{blue}a :{eoc} ") : ft_printf("a : ");
	print_stack(a, bonus->color);
	(bonus->size_stack) ? \
	ft_printf("\nsize = %d\n", stack_size(a)) : ft_printf("\n");
	(bonus->color) ? ft_printf("\n{blue}b :{eoc} ") : ft_printf("\nb : ");
	print_stack(b, bonus->color);
	(bonus->size_stack) ? \
	ft_printf("\nsize = %d\n", stack_size(b)) : ft_printf("\n");
	(bonus->color) ? ft_printf("{seawave}//////////////////////////////\
	{eoc}\n") : ft_printf("//////////////////////////////\n");
}

static t_bonus	*create_bonus(void)
{
	t_bonus	*bonus;

	if (!(bonus = (t_bonus*)malloc(sizeof(t_bonus))))
		return (NULL);
	bonus->num = 0;
	bonus->steps = 0;
	bonus->color = 0;
	bonus->operation = 0;
	bonus->size_stack = 0;
	bonus->help = 0;
	return (bonus);
}

int				main(int ac, char **av)
{
	int		i;
	t_stack *a;
	t_bonus *bonus;
	char	*line;
	char	**operations;

	bonus = create_bonus();
	operations = NULL;
	i = handle_flags(bonus, av);
	if (!(a = reader(ac, av, i)))
		return (0);
	(bonus->help) ? print_help() : 0;
	while (get_next_line(0, &line) > 0)
	{
		!check_valid(line) ? ft_error() : 0;
		operations = add_operation(operations, line);
		ft_strdel(&line);
	}
	if (checker(a, operations, bonus))
		(bonus->color) ? ft_printf("{green}OK{eoc}\n") : ft_printf("OK\n");
	else
		(bonus->color) ? ft_printf("{red}KO{eoc}\n") : ft_printf("KO\n");
	ft_free_arr(operations);
	return (0);
}
