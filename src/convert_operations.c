#include "../inc/push_swap.h"

static int			convert_arr(char **operations)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (operations[i])
	{
		if (operations[i] && operations[i + 1])
		{
			if ((!ft_strcmp(operations[i], "pa") && !ft_strcmp(operations[i + 1], "pb")) \
 			|| (!ft_strcmp(operations[i], "pb") && !ft_strcmp(operations[i + 1], "pa")) \
			|| (!ft_strcmp(operations[i], "ra") && !ft_strcmp(operations[i + 1], "rra")) \
 			|| (!ft_strcmp(operations[i], "rra") && !ft_strcmp(operations[i + 1], "ra")) \
 			|| (!ft_strcmp(operations[i], "rb") && !ft_strcmp(operations[i + 1], "rrb")) \
 			|| (!ft_strcmp(operations[i], "rrb") && !ft_strcmp(operations[i + 1], "rb")))
			{
				ft_memset(operations[i], '*', ft_strlen(operations[i]));
				ft_memset(operations[i + 1], '*', ft_strlen(operations[i + 1]));
				ret = 1;
			}
		}
		i++;
	}
	return (ret);
}

static char			**ret_new_operations(char **operations)
{
	int		i;
	int		j;
	int		size;
	char	**new_operations;

	i = 0;
	size = 0;
	while (operations[i])
	{
		if (!ft_strstr(operations[i], "*"))
			size++;
		i++;
	}
	if (!(new_operations = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (operations[j])
	{
		!ft_strstr(operations[j], "*") ? new_operations[i++] = ft_strdup(operations[j]) : 0;
		j++;
	}
	new_operations[i] = NULL;
	//ft_free_arr(operations);
	return (new_operations);
}

void		print_operations(char **operations)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (operations[i])
	{
		if (operations[i] && operations[i + 1])
		{
			if ((!ft_strcmp(operations[i], "sa") && !ft_strcmp(operations[i + 1], "sb")) || \
        (!ft_strcmp(operations[i], "sb") && !ft_strcmp(operations[i + 1], "sa"))) {
				ft_printf("%s\n", "ss");
				num++;
				i++;
			} else if ((!ft_strcmp(operations[i], "ra") && !ft_strcmp(operations[i + 1], "rb")) || \
        (!ft_strcmp(operations[i], "rb") && !ft_strcmp(operations[i + 1], "ra"))) {
				ft_printf("%s\n", "rr");
				num++;
				i++;
			} else if ((!ft_strcmp(operations[i], "rra") && !ft_strcmp(operations[i + 1], "rrb")) || \
        (!ft_strcmp(operations[i], "rrb") && !ft_strcmp(operations[i + 1], "rra"))) {
				ft_printf("%s\n", "rrr");
				num++;
				i++;
			} else {
				ft_printf("%s\n", operations[i]);
				num++;
			}
		}
		else {
			ft_printf("%s\n", operations[i]);
			num++;
		}
		i++;
	}
	ft_printf("num = %d\n", num);
}

char	**convert_operations(char **operations)
{
	int		ret;
	char	**new_operations;

	ret = convert_arr(operations);
	new_operations = ret_new_operations(operations);
	while (ret)
	{
		ret = convert_arr(new_operations);
		new_operations = ret_new_operations(new_operations);
	}
	return (new_operations);
}
