/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:06:15 by thbussir          #+#    #+#             */
/*   Updated: 2025/12/07 22:31:52 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack **a)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->nb < (*a)->next->next->nb || is_decreasing(*a))
		swap(a, a, "sa");
	if ((*a)->nb > (*a)->next->nb)
		rotate(a, a, "ra");
	else if (!is_sorted(*a))
		rotate(a, a, "rra");
}

static void	sort(t_stack **a, t_stack **b, int size_a)
{
	int	size_b;
	int	best_nb;

	if (is_sorted(*a))
		return ;
	size_b = size_a - 3;
	while (size_a-- > 3)
		push(a, b, "pb");
	size_a++;
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
	{
		best_nb = find_best_nb(*a, *b, size_a++, size_b--);
		move_nb_to_a(a, b, best_nb, size_a - 1);
	}
	while (find_index(*a, find_max(*a)) <= size_a / 2 && !is_sorted(*a))
		rotate(a, b, "ra");
	while (find_index(*a, find_max(*a)) > size_a / 2 && !is_sorted(*a))
		rotate(a, b, "rra");
	if (!is_sorted(*a))
		write(2, "Error\n", 6);
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
	sort(&a, &b, nb_val);
	free_stack(a, a->nb);
	return (1);
}
