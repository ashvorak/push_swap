/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:21:54 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/09 11:58:53 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack			*new_stack(int value)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

static	void	add_stack(t_stack **stack, int value)
{
	t_stack *tmp;
	t_stack *buf;

	if (!*stack)
		*stack = new_stack(value);
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		buf = new_stack(value);
		tmp->next = buf;
	}
}

t_stack			*reader(int ac, char **av)
{
	int		i;
	int		j;
	char	**arr;
	t_stack *a;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j])
		{
			if (is_valid(a, arr[j]))
				add_stack(&a, ft_atoi(arr[j]));
			else
				ft_error();
			j++;
		}
		ft_free_arr(arr);
		i++;
	}
	return (a);
}
