/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:14:12 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/19 19:41:27 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

static int is_flag(char *str)
{
	return (!ft_strcmp("-s", str) || !ft_strcmp("-n", str));
}

int	handle_flags(t_bonus *bonus,char **av)
{
	int i;

	i = 1;
	while (is_flag(av[i]))
	{
		if (!ft_strcmp("-n", av[i]))
			bonus->num = 1;
		if (!ft_strcmp("-s", av[i]))
			bonus->steps = 1;	
		i++;
	}
	return (i);
}
