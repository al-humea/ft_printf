/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:53:12 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/21 19:05:26 by al-humea         ###   ########.fr       */
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

char		*ft_itoa(int nbr)
{
	char	*str;
	int		m;
	long	nb;

	nb = nbr;
	m = 0;
	if (!(str = malloc(sizeof(char) * 12)))
		return (NULL);
	if (nb < 0)
	{
		str[m] = '-';
		nb *= -1;
		m++;
	}
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
