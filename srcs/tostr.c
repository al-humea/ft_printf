/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:18:40 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/26 19:39:04 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
**REMODEL S_TOSTR BASED ON DI_TOSTR
*/
char	*di_tostr(char *str, t_flags *flags)
{
	int		w_size;
	char	*tmp_num;
	char	*tmp_pad;

	w_size = ft_strlen(flags->data);
	if (flags->prec == -1)
		flags->prec = 1;
	if (flags->width < w_size)
		flags->width = w_size;
	tmp_num = adjust_nbr(flags); //Fct that takes the number and returns it with precision added or 0x0 if ptr
	tmp_pad = padded_space(flags, tmp_num);// returns an str with padded space
	if(flags->just == 1)
		str = ft_strjoin(tmp_num, tmp_pad);
	else
		str = ft_strjoin(tmp_pad, tmp_num);
	free(tmp_num);
	free(tmp_pad);
	return (str);
}

char	*s_tostr(char *str, t_flags *flags)
{
	int	w_size;

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