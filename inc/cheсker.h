/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheсker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:43:21 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/21 16:23:56 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEСKER_H
# define CHEСKER_H

#include "push_swap.h"

typedef struct	s_bonus
{
	int num;
	int steps;
	int color;
	int operation;
	int	size_stack;
	int help;
}				t_bonus;

int				checker(t_stack *a, char **operations, t_bonus *bonus);
void			print_stack(t_stack *stack, int is_color);
int				handle_flags(t_bonus *bonus,char **av);
void			print_steps(t_stack *a, t_stack *b, t_bonus *bonus, char *str);
void			free_stacks(t_stack *a, t_stack *b);
void			print_help(void);
int				check_valid(char *line);

#endif
