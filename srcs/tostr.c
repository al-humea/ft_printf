/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:18:40 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/17 10:29:10 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Converts flags->data from alpha uns to alpha hexadecimal + adds 0x0 if ptr
*/

char	*pointers_tostr(char *type, va_list args)
{
	void *ptr;

	ptr = NULL;
	ptr = va_arg(args, void *);
	if (!ptr)
	{
		if (*type == 'p')
			ptr = (void *)ft_strdup("(nil)");
		if (*type == 's')
			ptr = (void *)ft_strdup("(null)");
		*type = 'n';
	}
	else
	{
		if (*type == 'p')
			ptr = (void *)ft_lutoa((unsigned long)ptr);
		if (*type == 's')
			ptr = (void *)ft_strdup((char *)ptr);
	}
	return (ptr);
}

void	hexa_tostr(t_flags *flags)
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

/*
** Returns flags->data modified
*/

int		flags_tostr(t_flags *flags)
{
	int	size;

	if (ft_strsrc("%", flags->type) == 1)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (ft_strsrc("xXp", flags->type))
		hexa_tostr(flags);
	size = ft_strlen((char *)flags->data);
	addprecision(flags, size);
	if (flags->prec == 0 && ft_strsrc("diuxX", flags->type))
		if (((char *)flags->data)[0] == '0')
		{
			free(flags->data);
			flags->data = ft_strdup("");
		}
	if (flags->type == 'c')
		size = 1;
	else
		size = ft_strlen((char *)flags->data);
	size += addwidth(flags, size);
	return (size);
}

void	*data_tostr(char *type, va_list args)
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
