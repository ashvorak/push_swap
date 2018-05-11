/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:53:53 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/09 11:54:33 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <fcntl.h>
# include <stdlib.h>
# include "../lib/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/inc/ft_printf.h"

typedef	struct	s_stack
{
	int		value;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_game
{
	t_stack	*a;
	t_stack	*b;
}				t_game;

void			ft_error(void);
t_stack			*reader(int ac, char **av);
t_stack			*new_stack(int value);
int				is_valid(t_stack *stack, char *str);

void			swap(t_stack *stack);
void			push(t_stack **stack_from, t_stack **stack_to);
void			rotate(t_stack **stack);
void			reverse_rotate(t_stack **stack);

void			del_stack_head(t_stack **stack);

void			sort(t_game *game);
void			push_b(t_game *game);

void			print_stack(t_stack *stack);

#endif
