/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:05:17 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 18:35:36 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_arr(int *arr, int size)
{
	int i;
	int j;
	int buf;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[j + 1])
			{
				buf = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buf;
			}
			j++;
		}
		i--;
	}
}

int			return_base(t_stack *stack, int size)
{
	int		i;
	int		arr[size];
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (i < size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_arr(&arr[0], size);
	return (arr[size / 2]);
}
