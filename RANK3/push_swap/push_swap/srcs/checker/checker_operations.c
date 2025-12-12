/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:57:59 by thbussir          #+#    #+#             */
/*   Updated: 2025/12/10 17:56:11 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	checker_push(t_stack **x, t_stack **y, char *opt)
{
	t_stack	*temp;

	if (!*x)
		return ;
	temp = *x;
	if ((*x)->next == *x)
		*x = NULL;
	else
	{
		*x = stack_end(*x);
		(*x)->next = (*x)->next->next;
		(*x) = (*x)->next;
	}
	if (!*y)
		*y = temp;
	temp->next = *y;
	*y = stack_end(*y);
	(*y)->next = temp;
	*y = temp;
	(void)opt;
}

void	checker_do_swap(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*s || !(*s)->next)
		return ;
	if ((*s)->next->next == *s)
		*s = (*s)->next;
	else
	{
		tmp = *s;
		end = stack_end(*s);
		*s = (*s)->next;
		tmp->next = (*s)->next;
		(*s)->next = tmp;
		end->next = *s;
	}
}

void	checker_swap(t_stack **a, t_stack **b, char *opt)
{
	if (opt[1] != 'b')
		checker_do_swap(a);
	if (opt[1] != 'a')
		checker_do_swap(b);
}

void	checker_rotate(t_stack **a, t_stack **b, char *opt)
{
	if (*a && opt[1] != 'b' && !opt[2])
		*a = (*a)->next;
	if (*b && opt[1] != 'a' && !opt[2])
		*b = (*b)->next;
	if (*a && opt[2] && opt[2] != 'b')
		*a = stack_end(*a);
	if (*b && opt[2] && opt[2] != 'a')
		*b = stack_end(*b);
}
