/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:58:09 by thbussir          #+#    #+#             */
/*   Updated: 2025/12/07 22:32:07 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	i;
	int	start;

	if (!stack)
		return (0);
	i = 1;
	start = stack->nb;
	while (stack->next->nb != start && i++)
		stack = stack->next;
	return (i);
}

static int	rotate_both(t_stack **a, t_stack **b, int *idx, int *pos)
{
	int	s_a;
	int	s_b;

	s_a = stack_len(*a);
	s_b = stack_len(*b);
	while (*pos <= s_a / 2 && *idx <= s_b / 2 && *pos > 0 && (*idx)-- > 0)
	{
		rotate(a, b, "rr");
		*pos -= 1;
	}
	while (*pos > s_a / 2 && *idx > s_b / 2 && *pos < s_a && (*idx)++ < s_b)
	{
		rotate(a, b, "rrr");
		*pos += 1;
	}
	return (s_b);
}

void	move_nb_to_a(t_stack **a, t_stack **b, int nb, int size_a)
{
	int	pos;
	int	idx;
	int	size_b;

	pos = find_pos(*a, nb, size_a);
	idx = find_index(*b, nb);
	size_b = rotate_both(a, b, &idx, &pos);
	while (pos <= size_a / 2 && pos-- > 0)
		rotate(a, b, "ra");
	while (pos > size_a / 2 && pos++ < size_a)
		rotate(a, b, "rra");
	while (idx <= size_b / 2 && idx-- > 0)
		rotate(a, b, "rb");
	while (idx > size_b / 2 && idx++ < size_b)
		rotate(a, b, "rrb");
	push(b, a, "pa");
}
