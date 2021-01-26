/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:18:40 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/26 17:28:17 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*di_tostr(char *str, t_flags *flags)
{
	
}

char	*s_tostr(char *str, t_flags *flags)
{
	int w_size;

	w_size = ft_strlen(flags->data);
	if (flags->prec == -1)
		flags->prec = w_size;
	if ((w_size > flags->prec) && flags->prec >=0)
		w_size = flags->prec;
	if (flags->width < w_size)
		flags->width = w_size;
	str = malloc(sizeof(char) * (flags->width + 1));
	if (flags->just == 1)
	{
		ft_strlcpy(str, (char *)flags->data, flags->prec + 1);//for '\0'
		ft_fillwith(&str[flags->prec], ' ', flags->width - w_size);
		printf("jst : |%s|\n", str);
		return (str);
	}
	ft_fillwith(str, ' ', flags->width - w_size);
	ft_strlcpy(&str[flags->width - w_size], (char *)flags->data, flags->prec + 1);
	printf("njst : |%s|\n", str);
	return (str);
}