/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:56:39 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/19 08:46:14 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	skipformat(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strsrc("dciuspxX%", str[i]))
			return (i + 1);
		i++;
	}
	return (0);
}

/*
**checks if format is valid
*/

int	fmat_valider(const char *str)
{
	int	i;

	i = 1;
	if (!str || !str[i])
		return (-1);
	while (str[i])
	{
		if (ft_strsrc("dciuspxX%.-*0123456789", str[i]))
		{
			if (ft_strsrc("dciuspxX%", str[i]))
				return (++i);
			i++;
			continue ;
		}
		return (-1);
	}
	return (i + 1);
}

/*
** checks if formatS are valid using fmat valider returns
** the total number of % -1 if error in formats
*/

int	valid_fmat(const char *str)
{
	int	i;
	int	j;
	int	fmat_count;

	i = 0;
	j = 0;
	fmat_count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((j = fmat_valider(&str[i])) == -1)
				return (-1);
			fmat_count++;
			i += j;
			continue ;
		}
		i++;
	}
	return (fmat_count);
}

/*
** ADD THE SIZE FMATED ELEMENTS TO RETURN VALUE
*/

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		fmats_size;
	va_list	args;

	fmats_size = 0;
	i = 0;
	j = 0;
	if (valid_fmat(str) == -1)
		return (-1);
	va_start(args, str);
	while (str[i + j])
	{
		if (str[i + j] == '%')
		{
			j++;
			j += handling((char *)&str[i + j], args, &fmats_size);
			continue ;
		}
		ft_putchar_fd(str[i + j], 1);
		i++;
	}
	va_end(args);
	return (i + fmats_size);
}
