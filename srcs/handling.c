/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:13 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/17 18:13:47 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

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
			flags->data = data_tostr(flags, args);
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
	flags->width = f_width(format, args);
	flags->prec = f_prec(format, args);
	f_fmat(format, args, flags);
	flags->just = f_justifying(flags, format);
	flags->pad = f_padding(format, flags->prec);
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
**
**
**void printflags(t_flags *flags)
**{
**	printf("---\n");
**	printf("%c\n", flags->type);
**	printf("%d\n", flags->just);
**	printf("%c\n", flags->pad);
**	printf("%d\n", flags->width);
**	printf("%d\n", flags->prec);
**	printf("%s\n", flags->data);
**}
*/

int		handling(char *format, va_list args, int *fmats_size)
{
	t_flags		*flags;
	int			ret;

	flags = malloc(sizeof(t_flags));
	ret = get_flags(flags, format, args);
	*fmats_size += flags_tostr(flags);
	free(flags->data);
	free(flags);
	return (ret);
}
