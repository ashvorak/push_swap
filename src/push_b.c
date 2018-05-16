#include "../inc/push_swap.h"

int	stack_size(t_stack *stack)
{
	int size;
	t_stack *tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	sort_arr(int *arr, int size)
{
	int i;
	int j;
	int buf;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[j + 1])
			{
				buf = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buf;
			}
			j++;
		}
		i--;
	}
}

int	return_base(t_stack *stack, int size)
{
	int 	i;
	int		arr[size];
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (i < size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_arr(&arr[0], size);
	return (arr[size / 2]);
}

t_block *new_block(int size, int bottom)
{
	t_block *block;

	if (!(block = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	block->size = size;
	block->bottom = bottom;
	block->next = NULL;
	return (block);
}

void		push_block(t_game *game, int count, int bottom)
{
	t_block	*tmp;

	if (game->block)
	{
		tmp = new_block(count, bottom);
		tmp->next = game->block;
		game->block = tmp;
	}
	else
		game->block = new_block(count, bottom);
}

void		ret_bottom(t_game *game, int base)
{
	t_stack *tmp;

	tmp = game->a;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->value < base)
	{
		reverse_rotate(&game->a, &game->operations, "rra");
		tmp = game->a;
		while (tmp->next)
			tmp = tmp->next;
	}
}

void		push_b(t_game *game)
{
	int				i;
	int				size;
	int				base;
	int 			count;

	size = stack_size(game->a);
	while (size > 3)
	{
		base = return_base(game->a, size);
		i = 0;
		count = 0;
		ret_bottom(game, base);
		while (i < size)
		{
			if (is_need_push(game->a, base, size))
			{
				if (game->a->value < base)
				{
					push(&game->a, &game->b, &game->operations, "pb");
					count++;
				}
				else
					rotate(&game->a, &game->operations, "ra");
				i++;
			}
		}
		push_block(game, count, 0);
		size = stack_size(game->a);
	}
}
