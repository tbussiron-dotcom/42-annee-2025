/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:57:59 by thbussir          #+#    #+#             */
/*   Updated: 2025/12/07 22:32:00 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_end(t_stack *stack)
{
	int	start;

	if (!stack)
		return (NULL);
	start = stack->nb;
	while (stack->next->nb != start)
		stack = stack->next;
	return (stack);
}

void	add_back(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = new;
	}
}

static t_stack	*create_node(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	create_stack(t_stack **a, int *values, int nb_val)
{
	t_stack	*top;
	t_stack	*node;

	*a = NULL;
	add_back(a, create_node(values[--nb_val]));
	top = *a;
	while (nb_val)
	{
		node = create_node(values[--nb_val]);
		if (!node || !top)
		{
			ft_printf("Error");
			if (*a)
				free_stack(*a, (*a)->nb);
			free(values);
			*a = NULL;
			return ;
		}
		add_back(a, node);
	}
	add_back(a, top);
	*a = top;
	free(values);
}

void	free_stack(t_stack *stack, int top)
{
	if (!stack)
		return ;
	if (stack->next && stack->next->nb != top)
		free_stack(stack->next, top);
	free(stack);
}
