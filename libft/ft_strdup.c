/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:37:01 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/21 19:06:32 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*nstr;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	if (!(nstr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		nstr[i] = s1[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
