/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:13 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/21 19:01:37 by al-humea         ###   ########.fr       */
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

void	print_flags(t_flags *flags)
{
	printf("type : %c  |  data : %s\njst : %d  |  pad : %c\nprec : %d  |  width : %d\n\n",flags->type, flags->data, flags->just, flags->pad, flags->prec, flags->width);
}

/*
** needs to get unconverted format, get flags, convert format using flags, store converted formats in fmated
** using args if needed
** returns size of unconverted fmat to skip in "store_fmats"
*/
int		handling(char *format, va_list args, char **fmated)
{
	(void)fmated;
	//int static	i = 0; // use static to keep track of fmated number
	t_flags		*flags;
	int			ret;

	flags = malloc(sizeof(t_flags));
	if ((ret = get_flags(flags, format, args)) < 0)
		return (-1);
	print_flags(flags);
	//fmated[i] = flags_tostr(flags, args); flags to str being a function that returns a char *
	//i++;
	free(flags->data);
	free(flags);
	return (ret);
}