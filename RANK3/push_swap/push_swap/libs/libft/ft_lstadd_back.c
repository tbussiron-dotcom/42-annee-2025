/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:10:53 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/17 15:10:55 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	else if (!*lst)
		*lst = new;
	else if (!(*lst)->next)
		(*lst)->next = new;
	else
		ft_lstadd_back(&(*lst)->next, new);
}
