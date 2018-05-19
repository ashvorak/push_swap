/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:53:53 by oshvorak          #+#    #+#             */
/*   Updated: 2018/05/19 19:41:57 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "../lib/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/inc/ft_printf.h"

typedef	struct	s_stack
{
	int		value;
	struct s_stack	*next;
}				t_stack;

typedef	struct	s_block
{
	int		size;
	int		bottom;
	struct s_block *next;
}				t_block;

typedef struct	s_game
{
	t_stack	*a;
	t_stack	*b;
	int	a_remain;
	int	a_bottom;
	int	b_remain;
	char **operations;
	t_block *block;
}				t_game;

void			ft_error(void);
t_stack			*reader(int ac, char **av, int i);
t_stack			*new_stack(int value);
int				is_valid(t_stack *stack, char *str);

void			swap(t_stack *stack, char ***operations, char *operation);
void			push(t_stack **stack_from, t_stack **stack_to, char ***operations, char *operation);
void			rotate(t_stack **stack, char ***operations, char *operation);
void			reverse_rotate(t_stack **stack, char ***operations, char *operation);

void			del_stack_head(t_stack **stack);

void			sort(t_game *game);

void			push_a(t_game *game, int base, int size);
void			push_b(t_game *game);

int				stack_size(t_stack *stack);
int				return_base(t_stack *stack, int size);
t_block			*new_block(int size, int bottom);
void			push_block(t_game *game, int count, int bottom);
void			handle_block(t_game *game, t_block *block);
void			clean_a(t_game *game);

char			**add_operation(char **operations, char *operation);
int				is_sort(t_stack *stack);
void			print_stack(t_stack *stack);
char			**convert_operations(char **operations);
void			print_operations(char **operations);

#endif
