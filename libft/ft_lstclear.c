/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:02:38 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/21 14:36:45 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (!del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			tmp = lst[0]->next;
			ft_lstdelone(lst[0], del);
			lst[0] = tmp;
		}
	}
}
