/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:13 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/15 21:11:29 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int f_prec(const char *str)
{
	return (0);
}

int		f_width(const char *str)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (str[i])
	{
		if (ft_strsrc("123456789", str[i]))
		
		if (ft_strsrc("dciuspxX", str[i]))
		{
			i++;
			return (width);
		}
		i++;
	}
}

char	f_padding(const char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '0')
			return ('0');
		if (ft_strsrc("123456789dciuspxX."))
			return ('\0');
	}
	retyrb ('\0');
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

int		get_flags(t_flags *flags, char *format)
{

	flags->just = f_justifying(format);
	flags->pad = f_padding(format);
	flags->width = f_width(format);
	flags->prec = f_prec(format);
	/*
	flags->type = f_type(format);
	flags->space = f_space(format);
	*/

	return (0);
}

void	print_flags(t_flags flags)
{
	printf("jst : %d|pad : %c\nprec : %d|width : %d\n", flags.just, flags.pad, flags.prec, flags.width);
}

/*
** needs to get unconverted format, get flags, convert format using flags, store converted formats in fmated
** using args if needed
** returns size of unconverted fmat to skip in "store_fmats"
*/
int		handling(char *format, va_list args, char **fmated)
{
	(void)args, (void)fmated;
	int static	i = 0; // use static to keep track of fmated number
	t_flags		*flags;

	flags = malloc(sizeof(t_flags));
	if ((get_flags(flags, format)) < 0)
		return (-1);
	print_flags(*flags);
	free(flags);
	return (0);
}