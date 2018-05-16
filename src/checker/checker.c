#include "../../inc/cheсker.h"

static void	apply_operation(char *s, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
		!ft_strcmp(s, "pa") ? push(b, a, NULL, NULL) : push(a, b, NULL, NULL);
	else if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb"))
		!ft_strcmp(s, "sa") ? swap(*a, NULL, NULL) : swap(*b, NULL, NULL);
	else if (!ft_strcmp(s, "ss"))
	{
		swap(*a, NULL, NULL);
		swap(*b, NULL, NULL);
	}
	else if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb"))
		!ft_strcmp(s, "ra") ? rotate(a, NULL, NULL) : rotate(b, NULL, NULL);
	else if (!ft_strcmp(s, "rr"))
	{
		rotate(a, NULL, NULL);
		rotate(b, NULL, NULL);
	}
	else if (!ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb"))
		!ft_strcmp(s, "rra") ? \
		reverse_rotate(a, NULL, NULL) : reverse_rotate(b, NULL, NULL);
	else if (!ft_strcmp(s, "rrr"))
	{
		reverse_rotate(a, NULL, NULL);
		reverse_rotate(b, NULL, NULL);
	}
	else
		ft_error();
}

int	checker(t_stack *a, char **operations)
{
	int		i;
	t_stack *b;

	i = 0;
	b = NULL;
	if (operations)
	{
		while (operations[i])
		{
			apply_operation(operations[i], &a , &b);
			i++;
		}
	}
	if (!is_sort(a))
		return (0);
	return (1);
}

