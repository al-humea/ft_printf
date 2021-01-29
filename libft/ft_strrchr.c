/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:49:38 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/21 14:48:59 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int		i;

	i = ft_strlen(str) + 1;
	while (i--)
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	return (NULL);
}
