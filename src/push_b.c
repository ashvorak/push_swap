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
	i = 0;
	while (i < size)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("arr[size/2] %d\n", arr[ size / 2]);
	return (arr[size / 2]);
}

void		push_b(t_game *game)
{
	int 	i;
	int		size;
	int		base;
	t_stack	*tmp;

	size = stack_size(game->a);
	while (size > 3)
	{
		tmp = game->a;
		base = ret_base(game->a, size);
		i = 0;
		while (i < size)
		{
			if (tmp->value < base)
				push(&game->a, &game->b);
			else
				rotate(&game->a);
			ft_printf("stack a : ");
			print_stack(game->a);
			ft_printf("stack b : ");
			print_stack(game->b);
			i++;
			tmp = game->a;
		}
		size = stack_size(game->a);
	}
}
