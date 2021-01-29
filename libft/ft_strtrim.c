/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:50:18 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/21 14:38:00 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_makeword(char const *str, unsigned int start, unsigned int end)
{
	char			*s;
	unsigned int	i;

	if (!(s = malloc(end - start + 2)))
		return (NULL);
	i = 0;
	while (start <= end)
	{
		s[i] = str[start];
		i++;
		start++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strtrim(char const *str, char const *set)
{
	unsigned int	i;
	unsigned int	starto;
	unsigned int	endo;

	if (!str || !set)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!(ft_strchr(set, str[i])))
			break ;
		i++;
	}
	starto = i;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (!(ft_strchr(set, str[i])))
			break ;
		i--;
	}
	endo = i;
	return (ft_makeword(str, starto, endo));
}
