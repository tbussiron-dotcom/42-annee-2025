/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:45:36 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/17 18:46:16 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*newcont;

	if (!lst || !f || !del)
		return (NULL);
	newcont = f(lst->content);
	new = ft_lstnew(newcont);
	if (!new)
	{
		del(newcont);
		return (NULL);
	}
	if (lst->next)
	{
		new->next = ft_lstmap(lst->next, f, del);
		if (!new->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
	}
	return (new);
}
