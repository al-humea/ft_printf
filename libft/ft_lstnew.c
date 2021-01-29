/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:18:13 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/21 14:31:17 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_struct;

	if (!(new_struct = malloc(sizeof(t_list))))
		return (NULL);
	(*new_struct).content = content;
	(*new_struct).next = NULL;
	return (new_struct);
}
