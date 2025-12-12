/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:46:09 by yogun             #+#    #+#             */
/*   Updated: 2022/09/01 18:00:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	error(t_stack **a, t_stack **b)
{
	write(1, "Error\n", 6);
	if (*a)
		free_stack(*a, (*a)->nb);
	if (*b)
		free_stack(*b, (*b)->nb);
	exit(EXIT_FAILURE);
}

static void	check_sub(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		checker_rotate(a, b, "rra");
	else if (line[2] == 'b')
		checker_rotate(a, b, "rrb");
	else if (line[2] == 'r')
		checker_rotate(a, b, "rrr");
}

static char	*check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		checker_swap(a, b, "sa");
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		checker_swap(a, b, "sb");
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		checker_push(b, a, "pa");
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		checker_push(a, b, "pb");
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		checker_rotate(a, b, "ra");
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		checker_rotate(a, b, "rb");
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		checker_rotate(a, b, "rr");
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		checker_swap(a, b, "ss");
	else
	{
		free(line);
		error(a, b);
	}
	return (get_next_line(0));
}

static void	checker_sub(t_stack **a, t_stack **b)
{
	char	*tmp;
	char	*line;

	line = get_next_line(0);
	while (line && *line != '\n')
	{
		tmp = line;
		line = check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	if (line)
		free(line);
	if (*a)
		free_stack(*a, (*a)->nb);
	if (*b)
		free_stack(*b, (*b)->nb);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*values;
	int		nb_val;

	b = NULL;
	if (ac < 2)
		return (0);
	nb_val = parse(ac - 1, av + 1, &values);
	if (!values || !nb_val)
	{
		write(2, "Error\n", 6);
		if (values)
			free(values);
		return (0);
	}
	create_stack(&a, values, nb_val);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	checker_sub(&a, &b);
	return (1);
}
