/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:40:14 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/22 11:48:11 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** if no precision precision = size
*/

void	di_addprecision(t_flags *flags, char *str)
{
	int				num_size;
	unsigned int	difference;

	num_size = ft_strlen(flags->data);
	if (ft_atoi(flags->data) < 0)
	{
		difference = flags->prec - (num_size - 1);
		str = malloc(sizeof(char) * (flags->prec + 2));
		str[0] = '-';
		ft_fillwith(&str[1], '0', difference);
		ft_strlcpy(&str[1 + difference], &flags->data[1], num_size + 1);
	}
	else
	{
		difference = flags->prec - num_size;
		str = malloc(sizeof(char) * (flags->prec + 1));
		ft_fillwith(str, '0', difference);
		ft_strlcpy(&str[difference], flags->data, num_size + 1);
	}
	free(flags->data);
	flags->data = str;
}

void	addprecision(t_flags *flags, int size)
{
	char	*str;

	str = NULL;
	if (!ft_strsrc("di", flags->type) && flags->prec == -1)
		flags->prec = size;
	else if (flags->prec == -1 && ft_atoi(flags->data) < 0)
		flags->prec = size - 1;
	if ((flags->type == 's') && (flags->prec < size))
	{
		str = malloc(sizeof(char) * (flags->prec + 1));
		ft_strlcpy(str, flags->data, flags->prec + 1);
		free(flags->data);
		flags->data = str;
	}
	if (ft_strsrc("uxX", flags->type) && flags->prec > size)
	{
		str = malloc(sizeof(char) * (flags->prec + 1));
		ft_memset(str, '0', flags->prec - size);
		ft_strlcpy(&str[flags->prec - size], flags->data, size + 1);
		free(flags->data);
		flags->data = str;
	}
	if (ft_strsrc("di", flags->type) && flags->prec >= size)
		di_addprecision(flags, str);
	return ;
}

void	negnumberswidth(t_flags *flags, int zeros)
{
	if (flags->pad == '0')
	{
		if (ft_strsrc("di", flags->type) && (ft_atoi(flags->data) < 0))
		{
			ft_putchar_fd('-', 1);
			ft_spamc('0', zeros);
			ft_putstr_fd(&flags->data[1], 1);
			return ;
		}
		else
			ft_spamc('0', zeros);
	}
	else
		ft_spamc(' ', zeros);
	ft_putstr_fd(flags->data, 1);
}

int		addwidth(t_flags *flags, int size)
{
	if (flags->width > size)
	{
		if (flags->just == 1)
		{
			ft_putstrl_fd(flags->data, size, 1);
			ft_spamc(' ', flags->width - size);
		}
		else
		{
			if (ft_strsrc("diuxX", flags->type))
				negnumberswidth(flags, flags->width - size);
			else
			{
				ft_spamc(' ', flags->width - size);
				ft_putstrl_fd(flags->data, size, 1);
			}
		}
		return (flags->width - size);
	}
	ft_putstrl_fd(flags->data, size, 1);
	return (0);
}
