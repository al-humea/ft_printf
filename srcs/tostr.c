/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:18:40 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/27 23:03:22 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//Converts flags->data from alpha uns to alpha hexadecimal + adds 0x0 if ptr



void	hexaflags(t_flags flags)
{
	char				*str;
	unsigned long int	nbr;

	str = NULL;
	nbr = ft_atolu(flags->data);
	free(flags->data);
	if (flags->type == 'p')
	{
		str = ft_lutox(nbr);
		flags->data = ft_strjoin("0x", str);
		free(str);
	}
	else
		flags->data = ft_lutox(nbr);
	return ;
}