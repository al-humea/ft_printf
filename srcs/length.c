/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:40:14 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/01 18:41:29 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	addprecision(t_flags *flags, int size)
{
	char	*str;
	char	*tmpstr;

	tmpstr = NULL;
	str = NULL;
	if (flags->prec == -1)
		flags->prec = size;
	if ((flags->type == 's') && (flags->prec < size))
	{
		str = malloc(sizeof(char) * (flags->prec + 1));
		ft_strlcpy(str, flags->data, flags->prec + 1);
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
