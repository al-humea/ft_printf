/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:17:21 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/31 12:22:58 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	nbtoright(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	str[i + 1] = '\0';
	while (i > 0)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[i] = 0;
}

char		*ft_lutoa(unsigned long nbr)
{
	char *str;

	if (!(str = malloc(ft_nbrlen(nbr) + 1)))
		return (NULL);
	str[0] = 0;
	while (nbr >= 10)
	{
		nbtoright(str);
		str[0] = nbr % 10 + 48;
		nbr /= 10;
	}
	nbtoright(str);
	str[0] = nbr % 10 + 48;
	return (str);
}
