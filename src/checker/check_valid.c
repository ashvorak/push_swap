/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:18:12 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 16:44:36 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cheсker.h"

int	check_valid(char *line)
{
	if (!ft_strcmp(line, "pa") || !ft_strcmp(line, "pb") || \
	!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || \
	!ft_strcmp(line, "ss") || !ft_strcmp(line, "ra") ||
	!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr") ||
	!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || \
	!ft_strcmp(line, "rrr"))
		return (1);
	else
		return (0);
}
