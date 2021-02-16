/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutocx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:29:06 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/31 12:23:02 by al-humea         ###   ########.fr       */
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

char		*ft_lutocx(unsigned long nbr)
{
	char	*str;

	if (!(str = malloc(ft_nbrlen(nbr) + 1)))
		return (NULL);
	str[0] = '\0';
	while (nbr >= 16)
	{
		nbtoright(str);
		if ((nbr % 16) > 9)
			str[0] = (nbr % 16) - 10 + 'A';
		else
			str[0] = nbr % 16 + '0';
		nbr /= 16;
	}
	nbtoright(str);
	if ((nbr % 16) > 9)
		str[0] = (nbr % 16) - 10 + 'A';
	else
		str[0] = nbr % 16 + '0';
	return (str);
}
