/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:29:42 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/26 14:49:43 by al-humea         ###   ########.fr       */
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
	while(str[i])
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

void	*fmat_arg(char type, va_list args)
{
	(void)args, (void)type;
	void	*ptr;
	char	*tmps;

	tmps = NULL;
	ptr = NULL;//REMEMBER TO FREE
	if (type == 'p')
		ptr = (void *)ft_strdup(ft_lutoa(va_arg(args, unsigned long)));
	if (ft_strsrc("di", type))
		ptr = (void *)ft_strdup(ft_itoa(va_arg(args, int)));//REMEMBER TO TYPECAST
	if (ft_strsrc("uxX", type))
		ptr = (void *)ft_strdup(ft_utoa(va_arg(args, unsigned int)));
	if (type == 'c')
		ptr = (void *)ft_chardup(va_arg(args, int));
	if (type == 's')
	{
		tmps = va_arg(args, char *);
		ptr = (void *)ft_strdup(tmps);
	}
	if (type == '%')
		ptr = NULL;
	return (ptr);
}

// f format met data dans struct et set type
void	f_fmat(char *str, va_list args, t_flags *flags)
{
	(void)args;
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_strsrc("dciuspxX%", str[i]))
		{
			flags->type = str[i];
			flags->data = fmat_arg(str[i], args);
			break ;
		}
		i++;
	}
	return ;
}

void flags_bzero(t_flags *flags)
{
	flags->type = '\0';
	flags->data = NULL;
	flags->just = 0;
	flags->pad = 0;
	flags->prec = -1;
	flags->width = 0;
	return ;
}

int		get_flags(t_flags *flags, char *format, va_list args)
{
	int	fmat_size;

	fmat_size = 0;
	flags_bzero(flags);
	f_fmat(format, args, flags); // sets type + data
	flags->just = f_justifying(format);
	flags->pad = f_padding(format);
	flags->width = f_width(format, args);
	flags->prec = f_prec(format, args);
	while (format[fmat_size])
	{
		if (ft_strsrc("dciuspxX%", format[fmat_size]))
			return (++fmat_size);
		fmat_size++;
	}
	return (fmat_size);
}