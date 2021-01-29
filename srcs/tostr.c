/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:18:40 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/29 11:38:43 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converts flags->data from alpha uns to alpha hexadecimal + adds 0x0 if ptr
*/

void	hexaflags(t_flags *flags)
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
	if (flags->type == 'x')
		flags->data = ft_lutox(nbr);
	if (flags->type == 'X')
		flags->data = ft_lutocx(nbr);
	return ;
}

void	addprecision(t_flags *flags, int size)
{
	char	*str;
	char	*tmpstr;

	tmpstr = NULL;
	str = NULL;
	if ((flags->type == 's') && (flags->prec < size))
	{
		str = malloc(sizeof(char) * (flags->prec + 1));
		ft_strlcpy(str, flags->data, flags->prec + 1);
		str[flags->prec] = '\0';
		free(flags->data);
		flags->data = str;
		return ;
	}
	if (ft_strsrc("diuXx", flags->type) && flags->prec > size)
	{
		str = malloc(sizeof(char) * (flags->prec - size + 1));
		ft_fillwith(str, '0', flags->prec - size);
		tmpstr = ft_strjoin(str, flags->data);
		free(str);
		free(flags->data);
		flags->data = tmpstr;
		return ;
	}
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
