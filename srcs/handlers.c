/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:13 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/22 23:04:17 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_skip(char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (ft_strsrc("dciuspxX%", format[i]))
			return (i++);
		i++;
	}
	return (-1);
}

char	*flags_tostr(t_flags *flags)
{
	char	*str;

	str = NULL;

	if (ft_strsrc("dciuspxX", flags->type))
		str = malloc(2);
	str[0] = 'a';
	str[1] = '\0';

	if (flags->type == '%')
	{
		str = ft_chardup(flags->type);
		return (str);
	}
	return (str);
}

/*
** needs to get unconverted format, get flags, convert format using flags, store converted formats in fmated
** using args if needed
** returns size of unconverted fmat to skip in "store_fmats"
*/
int		handling(char *format, va_list args, char **fmated)
{
	(void) fmated;
	int static	i = 0; // use static to keep track of fmated number
	t_flags		*flags;
	int			ret;

	flags = malloc(sizeof(t_flags));
	if ((ret = get_flags(flags, format, args)) < 0)
		return (-1);
	fmated[i] = flags_tostr(flags);
	write(1, "fmated : ", 9);
	write(1, fmated[i], 2);
	write(1, "\n", 1);
	i++;
	free(flags->data);
	free(flags);
	return (ret);
}