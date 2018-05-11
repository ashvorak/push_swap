#include "../inc/push_swap.h"

static int	stack_size(t_stack *stack)
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

static void	sort_arr(int *arr, int size)
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

static int	ret_base(t_stack *stack, int size)
{
	int 	i;
	int		arr[size];
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_arr(&arr[0], size);
	return (arr[size / 2]);
}

t_block *new_block(int size)
{
	t_block *block;

	if (!(block = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	block->size = size;
	block->next = NULL;
	return (block);
}

void		push_block(t_game *game, int count)
{
	t_block	*tmp;

	if (game->block)
	{
		tmp = new_block(count);
		tmp->next = game->block;
		game->block = tmp;
	}
	else
		game->block = new_block(count);
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
		base = ret_base(game->a, size);
		i = 0;
		count = 0;
		while (i < size)
		{
			if (game->a->value < base)
			{
				push(&game->a, &game->b);
				count++;
			}
			else
				rotate(&game->a);
			i++;
		}
		push_block(game, count);
		size = stack_size(game->a);
	}
}
