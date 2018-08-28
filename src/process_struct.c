/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:05:00 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 16:31:23 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int		stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	del_stack_head(t_stack **stack)
{
	t_stack *tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

char	**add_operation(char **operations, char *operation)
{
	int		i;
	int		size;
	char	**new_operations;

	i = 0;
	size = (operations) ? ft_array_size(operations) : 0;
	if (!(new_operations = (char**)malloc(sizeof(char*) * (size + 2))))
		return (NULL);
	while (i < size)
	{
		new_operations[i] = ft_strdup(operations[i]);
		i++;
	}
	new_operations[i++] = ft_strdup(operation);
	new_operations[i] = NULL;
	ft_free_arr(operations);
	return (new_operations);
}

int		is_sort(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
