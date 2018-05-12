#include "../inc/push_swap.h"

void	sort_3elem(t_stack **stack)
{
	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			if ((*stack)->next->next && \
			(*stack)->value > (*stack)->next->next->value)
			{
				rotate(&*stack);
				if ((*stack)->value > (*stack)->next->value)
					swap(*stack);
			}
			else
				swap(*stack);
		}
		else
		{
			if ((*stack)->next->next && (*stack)->next->value > \
			(*stack)->next->next->value)
			{
				reverse_rotate(&*stack);
				(*stack) = *stack;
				if ((*stack)->value > (*stack)->next->value)
					swap(*stack);
			}
		}
	}
}

void	sort_3elem_top(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		swap(*stack);
	if ((*stack)->next->next && \
	(*stack)->next->next->value < (*stack)->next->value)
	{
		rotate(&*stack);
		swap(*stack);
		reverse_rotate(&*stack);
		if ((*stack)->next->value < (*stack)->value)
			swap(*stack);
	}
}
//переделать
void	clean_a(t_game *game)
{
	int	i;
	int base;
	int size;

	i = 0;
	base = return_base(game->a, game->a_remain);
	size = game->a_remain;
	while (i < size)
	{
		if (game->a->value < base)
		{
			push(&game->a, &game->b);
			game->a_remain--;
		}
		else
		{
			rotate(&game->a);
			game->b_remain++;
		}
		i++;
	}
}

void	push_a(t_game *game, int base, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (game->b->value >= base)
		{
			push(&game->b, &game->a);
			game->a_remain++;
		}
		else
		{
			rotate(&game->b);
			game->b_bottom++;
		}
		i++;
	}
}

void	sort(t_game *game)
{
	int i;
	int size;
	int base;

	sort_3elem(&game->a);
	while (stack_size(game->b))
	{
		size = game->block->size;
		base = return_base(game->b, size);
		push_a(game, base, size);
		del_block_head(&game->block);
		while (game->a_remain > 3)
			clean_a(game);
		sort_3elem_top(&game->a);
		(game->b_remain + game->b_bottom != 0) ? push_block(game, game->b_remain + game->b_bottom) : 0;
		i = 0;
		while (i < game->b_bottom)
		{
			reverse_rotate(&game->b);
			i++;
		}
		game->a_remain = 0;
		game->b_remain = 0;
		game->b_bottom = 0;
	}
}
