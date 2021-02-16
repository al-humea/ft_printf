/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:29:42 by al-humea          #+#    #+#             */
/*   Updated: 2021/02/15 20:45:23 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		f_prec(const char *str, va_list args)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
				return (va_arg(args, int));
			if (ft_strsrc("0123456789", str[i]))
				return (ft_atoi(&str[i]));
		}
		if (ft_strsrc("dciuspxX%", str[i]))
			return (-1);
		i++;
	}
	return (-1);
}

int		f_width(const char *str, va_list args)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (va_arg(args, int));
		if (ft_strsrc("123456789", str[i]))
			return (ft_atoi(&str[i]));
		if (ft_strsrc(".dciuspxX%", str[i]))
		{
			i++;
			return (width);
		}
		i++;
	}
	return (0);
}

char	f_padding(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return ('0');
		if (ft_strsrc("123456789.dciuspxX%", str[i]))
			return ('\0');
		i++;
	}
	return ('\0');
}

int		f_justifying(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		if (ft_strsrc(".dciuspxX%", str[i]))
			return (0);
		i++;
	}
	return (0);
}

/*
** PBM étant de savoir quand (null) est un vrai (null) ou un
** null envoyé en paramètre (pour gerer width prec)
*/

void	*fmat_arg(char *type, va_list args)
{
	void	*ptr;
	char	*tmps;

	tmps = NULL;
	ptr = NULL;
	if (*type == 'p' || *type == 's')
		ptr = (void *)pointers_tostr(type, args);
	if (ft_strsrc("di", *type))
		ptr = (void *)ft_itoa(va_arg(args, int));
	if (ft_strsrc("uxX", *type))
		ptr = (void *)ft_utoa(va_arg(args, unsigned int));
	if (*type == 'c')
		ptr = (void *)ft_chardup(va_arg(args, int));
	if (*type == '%')
		ptr = (void *)ft_chardup('%');
	return (ptr);
}
