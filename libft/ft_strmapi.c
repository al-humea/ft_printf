/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:01:06 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/18 14:49:05 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstr;

	if (!str || !f)
		return (NULL);
	if (!(nstr = malloc(ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		nstr[i] = (*f)(i, str[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
