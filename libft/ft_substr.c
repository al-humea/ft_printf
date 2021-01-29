/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:37:37 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/21 14:52:15 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int starto, size_t len)
{
	char	*sub;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	if (!starto && !str)
		return (NULL);
	if (ft_strlen(str) < starto)
		return (ft_strdup(""));
	if (!(sub = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		sub[i] = str[starto + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
