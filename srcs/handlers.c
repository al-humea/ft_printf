/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:13 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/27 23:03:20 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Returns flags->data modified
char	*flags_tostr(t_flags *flags)
{
	unsigned int	size;
	if (flags->type == '%')
		return (flags->data);
	if (ft_strsrc("xXp", flags->type))
		hexaflags(flags);
	size = ft_strlen((char *)flags->data);
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

/*
** needs to get unconverted format, get flags, convert format using flags, store converted formats in fmated
** using args if needed
** returns size of unconverted fmat to skip in "store_fmats"
*/
int		handling(char *format, va_list args, char **fmated)
{
	(void)fmated;
	int static	i = 0; // use static to keep track of fmated number
	t_flags		*flags;
	int			ret;

	flags = malloc(sizeof(t_flags));
	ret = get_flags(flags, format, args)
	fmated[i] = flags_tostr(flags);
	i++;
//	free(flags->data); cause we use it 
	free(flags);
	return (ret);
}