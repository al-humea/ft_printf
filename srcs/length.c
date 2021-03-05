/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:40:14 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/05 18:49:28 by al-humea         ###   ########.fr       */
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
		num_size -= 1;
		difference = flags->prec - num_size;
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
	if (flags->prec == -1)
		flags->prec = size;
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
		ft_strlcpy(&str[flags->prec - size], flags->data, size);
		free(flags->data);
		flags->data = str;
	}
	if (ft_strsrc("di", flags->type) && flags->prec >= size)
		di_addprecision(flags, str);
	return ;
}

char	*addwidth2(t_flags *flags, int size, char *tmpstr)
{
	int rtn;

	rtn = ft_strsrc("diuxX", flags->type);
	if (rtn && flags->pad == '0' && flags->prec == -1)
		ft_fillwith(tmpstr, '0', flags->width - size);
	else
		ft_fillwith(tmpstr, ' ', flags->width - size);
	return (ft_strjoin(tmpstr, flags->data));
}

void	addwidth(t_flags *flags, int size)
{
	char	*str;
	char	*tmpstr;

	str = NULL;
	tmpstr = NULL;
	if (flags->width > size)
	{
		tmpstr = malloc(sizeof(char) * (flags->width - size + 1));
		if (flags->just == 1)
		{
			ft_fillwith(tmpstr, ' ', flags->width - size);
			str = ft_strjoin(flags->data, tmpstr);
		}
		else
			str = addwidth2(flags, size, tmpstr);
		free(flags->data);
		free(tmpstr);
		flags->data = str;
	}
	return ;
}
