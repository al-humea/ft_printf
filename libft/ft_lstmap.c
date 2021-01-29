/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:03:48 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/21 18:05:06 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*f_mapped;

	if (!lst)
		return (NULL);
	if (!(mapped = malloc(sizeof(lst))))
		return (NULL);
	f_mapped = mapped;
	while (lst)
	{
		mapped->content = f(lst->content);
		if (!(mapped->next = malloc(sizeof(lst))))
		{
			ft_lstclear(&f_mapped, del);
			return (NULL);
		}
		mapped = mapped->next;
		lst = lst->next;
	}
	return (f_mapped);
}
