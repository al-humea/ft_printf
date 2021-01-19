/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:09 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/15 21:11:28 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_strsrc(const char *str, int src)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == src)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					mlt;
	int					nbr;
	unsigned int		i;

	i = 0;
	nbr = 0;
	mlt = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			mlt *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * mlt);
}