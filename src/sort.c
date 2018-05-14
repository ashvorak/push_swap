#include "../inc/push_swap.h"

void	sort_3elem(t_stack **stack, char ***operations)
{
	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			if ((*stack)->next->next && \
			(*stack)->value > (*stack)->next->next->value)
			{
				rotate(&*stack, operations, "ra");
				if ((*stack)->value > (*stack)->next->value)
					swap(*stack, operations, "sa");
			}
			else
				swap(*stack, operations, "sa");
		}
		else
		{
			if ((*stack)->next->next && (*stack)->next->value > \
			(*stack)->next->next->value)
			{
				reverse_rotate(&*stack, operations, "rra");
				(*stack) = *stack;
				if ((*stack)->value > (*stack)->next->value)
					swap(*stack, operations, "sa");
			}
		}
	}
}

void	sort_3elem_top(t_stack **stack, char ***operations)
{
	if ((*stack)->value > (*stack)->next->value)
		swap(*stack, operations, "sa");
	if ((*stack)->next->next && \
	(*stack)->next->next->value < (*stack)->next->value)
	{
		rotate(&*stack, operations, "ra");
		swap(*stack, operations, "sa");
		reverse_rotate(&*stack, operations, "rra");
		if ((*stack)->next->value < (*stack)->value)
			swap(*stack, operations, "sa");
	}
}

void	clean_a(t_game *game)
{
	int	i;
	int base;
	int size;

	i = 0;
	base = return_base(game->a, game->a_remain);
	game->b_remain = 0;
	size = game->a_remain;
	while (i < size)
	{
		if (game->a->value < base)
		{
			push(&game->a, &game->b, &game->operations, "pb");
			game->a_remain--;
			game->b_remain++;
		}
		else
		{
			rotate(&game->a, &game->operations, "ra");
			game->a_bottom++;
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
			push(&game->b, &game->a, &game->operations, "pa");
			game->a_remain++;
		}
		else
		{
			rotate(&game->b, &game->operations, "rb");
			game->block->bottom++;
		}
		game->block->size--;
		i++;
	}
}

void 	fix_stack_a(t_game *game)
{
	int i;

	i = 0;
	while (i < game->a_bottom)
	{
		reverse_rotate(&game->a, &game->operations, "rra");
		i++;
	}
	game->a_bottom = 0;
}

void 	fix_block(t_game *game, t_block *block)
{
	int i;

	i = 0;
	while (i < block->bottom)
	{
		reverse_rotate(&game->b, &game->operations, "rrb");
		block->size++;
		i++;
	}
	block->bottom = 0;
}

void	sort(t_game *game)
{
	int size;
	int base;

	sort_3elem(&game->a, &game->operations);
	while (stack_size(game->b))
	{
		fix_block(game, game->block);
		size = game->block->size;
		base = return_base(game->b, size);
		push_a(game, base, size);
		(!game->block->size && !game->block->bottom) ? del_block_head(&game->block) : 0;
		while (game->a_remain > 3)
		{
			fix_stack_a(game);
			clean_a(game);
			(game->b_remain) ? push_block(game, game->b_remain, 0) : 0;
		}
		fix_stack_a(game);
		game->a_remain = 0;
		game->b_remain = 0;
		sort_3elem_top(&game->a, &game->operations);
	}
}
