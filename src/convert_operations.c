/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:53 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 15:40:27 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int			convert_arr(char **op)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (op[i])
	{
		if (op[i] && op[i + 1])
		{
			if ((!ft_strcmp(op[i], "pa") && !ft_strcmp(op[i + 1], "pb")) \
			|| (!ft_strcmp(op[i], "pb") && !ft_strcmp(op[i + 1], "pa")) \
			|| (!ft_strcmp(op[i], "ra") && !ft_strcmp(op[i + 1], "rra")) \
			|| (!ft_strcmp(op[i], "rra") && !ft_strcmp(op[i + 1], "ra")) \
			|| (!ft_strcmp(op[i], "rb") && !ft_strcmp(op[i + 1], "rrb")) \
			|| (!ft_strcmp(op[i], "rrb") && !ft_strcmp(op[i + 1], "rb")))
			{
				ft_memset(op[i], '*', ft_strlen(op[i]));
				ft_memset(op[i + 1], '*', ft_strlen(op[i + 1]));
				ret = 1;
			}
		}
		i++;
	}
	return (ret);
}

static char			**ret_new_operations(char **op)
{
	int		i;
	int		j;
	int		size;
	char	**new_operations;

	i = 0;
	size = 0;
	while (op[i])
	{
		if (!ft_strstr(op[i], "*"))
			size++;
		i++;
	}
	if (!(new_operations = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (op[j])
	{
		!ft_strstr(op[j], "*") ? new_operations[i++] = ft_strdup(op[j]) : 0;
		j++;
	}
	new_operations[i] = NULL;
	ft_free_arr(op);
	return (new_operations);
}

char				**convert_operations(char **operations)
{
	int		ret;
	char	**new_operations;

	ret = convert_arr(operations);
	new_operations = ret_new_operations(operations);
	while (ret)
	{
		ret = convert_arr(new_operations);
		new_operations = ret_new_operations(new_operations);
	}
	return (new_operations);
}
