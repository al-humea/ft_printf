/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:51:23 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/31 12:22:17 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joint;
	size_t	size;
	size_t	i;
	size_t	i2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	i2 = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(joint = malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		if (i < ft_strlen(s1))
			joint[i] = s1[i];
		else
		{
			joint[i] = s2[i2];
			i2++;
		}
		i++;
	}
	joint[i] = '\0';
	return (joint);
}