/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::        */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	      */
/*   By: thbussir <marvin@42.fr>					+#+  +:+	   +#+	 	  */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2025/12/06 20:12:19 by thbussir		  #+#	#+#			      */
/*   Updated: 2025/12/07 22:31:45 by thbussir         ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_pos(t_stack *a, int nb, int size_a)
{
	int	closest;
	int	start;
	int	index;

	index = 0;
	start = a->nb;
	closest = find_min(a);
	if (nb < closest)
	{
		index = find_index(a, find_max(a)) + 1;
		return (index);
	}
	while (a->next->nb != start)
	{
		if (nb > a->nb && closest < a->nb)
			closest = a->nb;
		a = a->next;
	}
	if (nb > a->nb && closest < a->nb)
		closest = a->nb;
	index = find_index(a, closest);
	if (index >= size_a)
		index = 0;
	return (index);
}

static int	count_rr_rrr(t_stack *a, t_stack *b, int *idx, int *pos)
{
	int	s_a;
	int	s_b;
	int	nb_opt;

	s_a = stack_len(a);
	s_b = stack_len(b);
	nb_opt = 0;
	while (*pos <= s_a / 2 && *idx <= s_b / 2 && *pos > 0 && (*idx)-- > 0)
	{
		nb_opt++;
		*pos -= 1;
	}
	while (*pos > s_a / 2 && *idx > s_b / 2 && *pos < s_a && (*idx)++ < s_b)
	{
		nb_opt++;
		*pos += 1;
	}
	return (nb_opt);
}

int	find_nb_opt(t_stack *a, t_stack *b, int nb, int size_a)
{
	int	pos;
	int	idx;
	int	nb_opt;
	int	size_b;

	pos = find_pos(a, nb, size_a);
	idx = find_index(b, nb);
	size_b = stack_len(b);
	nb_opt = count_rr_rrr(a, b, &idx, &pos);
	while (pos <= size_a / 2 && pos-- > 0)
		nb_opt++;
	while (pos > size_a / 2 && pos++ < size_a)
		nb_opt++;
	while (idx <= size_b / 2 && idx-- > 0)
		nb_opt++;
	while (idx > size_b / 2 && idx++ < size_b)
		nb_opt++;
	return (nb_opt + 1);
}

int	find_best_nb(t_stack *a, t_stack *b, int size_a, int size_b)
{
	int		nb_opt;
	int		min_nb_opt;
	int		best_nb;
	t_stack	*temp;
	int		i;

	temp = b;
	min_nb_opt = find_nb_opt(a, b, b->nb, size_a);
	best_nb = b->nb;
	b = b->next;
	i = 0;
	while (i < size_b)
	{
		nb_opt = find_nb_opt(a, b, temp->nb, size_a);
		if (nb_opt < min_nb_opt)
		{
			best_nb = temp->nb;
			min_nb_opt = nb_opt;
		}
		temp = temp->next;
		i++;
	}
	return (best_nb);
}
