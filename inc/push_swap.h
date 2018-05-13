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

typedef	struct	s_block
{
	int		size;
	struct s_block *next;
}				t_block;

typedef struct	s_game
{
	t_stack	*a;
	t_stack	*b;
	int	a_remain;
	int a_bottom;
	int	b_remain;
	int	b_bottom;
	t_block *block;
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
void			del_block_head(t_block **block);

void			sort(t_game *game);

void			push_b(t_game *game);

int				stack_size(t_stack *stack);
void			sort_arr(int *arr, int size);
int				return_base(t_stack *stack, int size);
t_block			*new_block(int size);
void			push_block(t_game *game, int count);

void			print_stack(t_stack *stack);

#endif
