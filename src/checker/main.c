#include "../../inc/cheсker.h"

int main(int ac, char **av)
{
	t_stack *a;
	char	*line;
	char	**operations;

	if (ac > 1)
	{
		operations = NULL;
		a = reader(ac, av);
		while (get_next_line(0, &line) > 0)
			operations = add_operation(operations, line);
		if (checker(a, operations))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_error();
	return (0);
}
