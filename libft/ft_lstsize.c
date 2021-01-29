/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:36:01 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/19 19:11:37 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*nlst;

	if (!lst)
		return (0);
	i = 1;
	nlst = lst->next;
	while (nlst)
	{
		nlst = nlst->next;
		i++;
	}
	return (i);
}
