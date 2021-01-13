/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:56:39 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/13 19:21:59 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	store_fmats(const char *str, va_list args, char **fmated)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			
		}
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	char	**fmated;

	i = 0;
	va_start(args, str);
	if((store_fmats(str, args, fmated)) == -1)
		return (-1);
	va_end(args);

	return (i);
}