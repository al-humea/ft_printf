/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:13 by al-humea          #+#    #+#             */
/*   Updated: 2021/02/15 20:45:23 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Returns flags->data modified
*/

char	*flags_tostr(t_flags *flags)
{
	int	size;

	if (ft_strsrc("n%", flags->type) == 1)
		return (flags->data);
	if (ft_strsrc("xXp", flags->type))
		hexaflags(flags);
	size = ft_strlen((char *)flags->data);
	addprecision(flags, size);
	size = ft_strlen((char *)flags->data);
	addwidth(flags, size);
	return (flags->data);
}

/*
** f format met data dans struct et set type
*/

void	f_fmat(char *str, va_list args, t_flags *flags)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strsrc("dciuspxX%", str[i]))
		{
			flags->type = str[i];
			flags->data = fmat_arg(&flags->type, args);
			break ;
		}
		i++;
	}
	return ;
}

void	flags_bzero(t_flags *flags)
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
	f_fmat(format, args, flags);
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

/*
** needs to get unconverted format, get flags, convert format using flags,
** store converted formats in fmated using args if needed
** returns size of unconverted fmat to skip in "store_fmats"
*/

int		handling(char *format, va_list args, char **fmated)
{
	t_flags		*flags;
	int			ret;

	flags = malloc(sizeof(t_flags));
	ret = get_flags(flags, format, args);
	*fmated = flags_tostr(flags);
	free(flags);
	return (ret);
}
