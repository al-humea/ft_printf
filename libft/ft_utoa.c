/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:37:40 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/31 12:25:02 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	nbtoright(char *str, int m)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	str[i + 1] = '\0';
	while (i > m)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[i] = 0;
}

char		*ft_utoa(unsigned int nbr)
{
	char			*str;
	int				m;
	unsigned int	nb;

	nb = nbr;
	m = 0;
	if (!(str = malloc(sizeof(char) * (ft_nbrlen(nbr) + 1))))
		return (NULL);
	str[m] = '\0';
	while (nb > 9)
	{
		nbtoright(str, m);
		str[m] = (nb % 10) + 48;
		nb /= 10;
	}
	nbtoright(str, m);
	str[m] = nb + 48;
	return (str);
}
