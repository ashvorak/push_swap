/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:14:12 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 14:27:49 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

static int	is_flag(char *str)
{
	return (!ft_strcmp("-s", str) || !ft_strcmp("-n", str) \
	|| !ft_strcmp("-ss", str) || !ft_strcmp("-c", str) \
	|| !ft_strcmp("-o", str) || !ft_strcmp("-h", str));
}

int			handle_flags(t_bonus *bonus, char **av)
{
	int i;

	i = 1;
	if (av[i])
	{
		while (av[i] && is_flag(av[i]))
		{
			if (!ft_strcmp("-n", av[i]))
				bonus->num = 1;
			else if (!ft_strcmp("-s", av[i]))
				bonus->steps = 1;
			else if (!ft_strcmp("-ss", av[i]))
				bonus->size_stack = 1;
			else if (!ft_strcmp("-o", av[i]))
				bonus->operation = 1;
			else if (!ft_strcmp("-c", av[i]))
				bonus->color = 1;
			else if (!ft_strcmp("-h", av[i]))
				bonus->help = 1;
			i++;
		}
	}
	return (i);
}
