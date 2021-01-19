/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:29:42 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/19 19:08:09 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int f_prec(const char *str, va_list args)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
				return (va_arg(args, int))
			if (ft_strsrc("0123456789", str[i]))
				return (ft_atoi(&str[i]));
		}
		if (ft_strsrc("dciuspxX%", str[i]))
			return (0);
		i++;
	}
	return (0);
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
	while(str[i])
	{
		if (str[i] == '0')
			return ('0');
		if (ft_strsrc("123456789.dciuspxX%"))
			return ('\0');
	}
	return ('\0');
}
int		f_justifying(const char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '-')
			return(1);
		if (ft_strsrc(".dciuspxX%", str[i]))
			return (0);
		i++;
	}
	return (0);
}

// f format met data dans struct et set type
void	f_format(char *str, va_list args, t_flags *flags)
{
	return ;
}

int		get_flags(t_flags *flags, char *format, va_list args)
{
	int	fmat_size;

	f_format(format, args, flags); // sets type + data
	flags->just = f_justifying(format);
	flags->pad = f_padding(format);
	flags->width = f_width(format, args);
	flags->prec = f_prec(format, args);

	return (0);
}