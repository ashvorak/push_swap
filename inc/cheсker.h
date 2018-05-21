/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheсker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:43:21 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/19 19:43:23 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEСKER_H
# define CHEСKER_H

#include "push_swap.h"

typedef struct	s_bonus
{
	int num;
	int steps;
}				t_bonus;

int				checker(t_stack *a, char **operations, t_bonus *bonus);
void			print_stack(t_stack *stack);
int				handle_flags(t_bonus *bonus,char **av);
void			print_steps(t_stack *a, t_stack *b);

#endif
