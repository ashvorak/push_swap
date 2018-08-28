/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:28:22 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 15:45:47 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	print_operation(char *oper1, char *oper2)
{
	if ((!ft_strcmp(oper1, "sa") && !ft_strcmp(oper2, "sb")) || \
	(!ft_strcmp(oper1, "sb") && !ft_strcmp(oper2, "sa")))
	{
		ft_printf("%s\n", "ss");
		return (1);
	}
	else if ((!ft_strcmp(oper1, "ra") && !ft_strcmp(oper2, "rb")) || \
	(!ft_strcmp(oper1, "rb") && !ft_strcmp(oper2, "ra")))
	{
		ft_printf("%s\n", "rr");
		return (1);
	}
	else if ((!ft_strcmp(oper1, "rra") && !ft_strcmp(oper2, "rrb")) || \
	(!ft_strcmp(oper1, "rrb") && !ft_strcmp(oper2, "rra")))
	{
		ft_printf("%s\n", "rrr");
		return (1);
	}
	else
		ft_printf("%s\n", oper1);
	return (0);
}

void		print_operations(char **operations)
{
	int i;

	i = 0;
	while (operations[i])
	{
		if (operations[i] && operations[i + 1])
			i += print_operation(operations[i], operations[i + 1]);
		else
			ft_printf("%s\n", operations[i]);
		i++;
	}
}
