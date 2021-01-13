/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:13 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/12 14:45:01 by al-humea         ###   ########.fr       */
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

int		f_prec(char *format)
{
	return (0);
}

int		f_width(char *format)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while(ft_strsrc("dciuspxX%", format[i]) == 0)
	{
		if (format[i] == '-')
			i++;
		if (format[i] == '0')
			i++;
		if (format[i] > 48 && format[i] < 58)
		{
			width = ft_atoi(&format[i]);
			return (width);
		}
		if (format[i] == '.')
			return (width);
		i++;
	}
	return (0);
}

char	f_padding(char *format)
{
	int		i;
	char	pad;

	i = 0;
	pad = 0;
	while(ft_strsrc("dciuspxX%", format[i]) == 0)
	{
		if (format[i] == '-')
			return (pad);
		if (format[i] == '0')
		{
			pad = '0';
			return (pad);
		}
		if (format[i] > 48 && format[i] < 58)
			return (pad);
		if (format[i] == '.')
			return (pad);
		i++;
	}
	return (pad);
}

int		f_justifying(char *format)
{
	int i;
	int jst;

	i = 0;
	jst = 0;
	while(ft_strsrc("dciuspxX%", format[i]) == 0)
	{
		if (format[i] == '-')
		{
			jst = 1;
			return (jst);
		}
		if (format[i] == '0')
			return (jst);
		if (format[i] > 48 && format[i] < 58)
			return (jst);
		if (format[i] == '.')
			return (jst);
		i++;
	}
	return (jst);
}

int		get_flags(t_flags *flags, char *format)
{
	flags->just = f_justifying(format);
	flags->pad = f_padding(format);
	flags->width = f_width(format);
	flags->prec = f_prec(format);

	return (0);
}

void	print_flags(t_flags flags)
{
	printf("jst : %d|pad : %c\nprec : %d|width : %d\n", flags.just, flags.pad, flags.prec, flags.width);
}

int		handling(char *format)
{
	t_flags *flags;

	flags = malloc(sizeof(t_flags));
	if ((get_flags(flags, format)) < 0)
		return (-1);
	print_flags(*flags);
	return (0);
}