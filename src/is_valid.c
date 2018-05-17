/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:58 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/17 15:20:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static ssize_t	ft_atoi_ssize_t(const char *str)
{
	int					i;
	ssize_t				res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (res > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}

static void		check_dublicate(t_stack *stack, int value)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			ft_error();
		tmp = tmp->next;
	}
}

int				is_valid(t_stack *stack, char *str)
{
	int		i;
	ssize_t	value;

	i = (*str == '-') ? 1 : 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	value = ft_atoi_ssize_t(str);
	if (value < -2147483648 || value > 2147483647)
		ft_error();
	check_dublicate(stack, (int)value);
	return (1);
}
