/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:06:15 by thbussir          #+#    #+#             */
/*   Updated: 2025/11/29 22:03:42 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_decreasing(t_stack *stack)
{
	int	top;

	top = stack->nb;
	while (stack->next->nb != top)
	{
		if (stack->nb < stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int	top;

	top = stack->nb;
	while (stack->next->nb != top)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	int	start;
	int	min;

	start = stack->nb;
	min = stack->nb;
	stack = stack->next;
	while (stack->nb != start)
	{
		if (min > stack->nb)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	start;
	int	max;

	start = stack->nb;
	max = stack->nb;
	stack = stack->next;
	while (stack->nb != start)
	{
		if (max < stack->nb)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

int	find_index(t_stack *stack, int nb)
{
	int	index;

	index = 0;
	while (stack->nb != nb)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}
