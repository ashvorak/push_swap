/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:04 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 14:27:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

static void	ss(t_stack *a, t_stack *b)
{
	swap(a, NULL, NULL);
	swap(b, NULL, NULL);
}

static void	rr(t_stack **a, t_stack **b)
{
	rotate(a, NULL, NULL);
	rotate(b, NULL, NULL);
}

static void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, NULL, NULL);
	reverse_rotate(b, NULL, NULL);
}

static void	apply_operation(char *s, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
		!ft_strcmp(s, "pa") ? push(b, a, NULL, NULL) : push(a, b, NULL, NULL);
	else if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb"))
		!ft_strcmp(s, "sa") ? swap(*a, NULL, NULL) : swap(*b, NULL, NULL);
	else if (!ft_strcmp(s, "ss"))
		ss(*a, *b);
	else if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb"))
		!ft_strcmp(s, "ra") ? rotate(a, NULL, NULL) : rotate(b, NULL, NULL);
	else if (!ft_strcmp(s, "rr"))
		rr(a, b);
	else if (!ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb"))
		!ft_strcmp(s, "rra") ? \
		reverse_rotate(a, NULL, NULL) : reverse_rotate(b, NULL, NULL);
	else if (!ft_strcmp(s, "rrr"))
		rrr(a, b);
	else
		ft_error();
}

int			checker(t_stack *a, char **operations, t_bonus *bonus)
{
	int		i;
	t_stack *b;

	i = 0;
	b = NULL;
	if (operations)
	{
		while (operations[i])
		{
			apply_operation(operations[i], &a, &b);
			(bonus->steps) ? print_steps(a, b, bonus, operations[i]) : 0;
			i++;
		}
	}
	(bonus->num) ? ft_printf("\nnumber of operations = %d\n\n", i) : 0;
	if (!is_sort(a))
	{
		while (a)
			del_stack_head(&a);
		return (0);
	}
	while (a)
		del_stack_head(&a);
	return (1);
}
