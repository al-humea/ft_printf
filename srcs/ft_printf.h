/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:51 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/13 19:16:55 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
// to remove
# include "stdio.h"

typedef struct s_flags
{
	int		just;
	char	pad;
	int		width;
	int		prec;
} t_flags;


int		ft_atoi(const char *str);
char	ft_strsrc(const char *str, int src);
int		f_prec(char *format);
int		f_width(char *format);
char	f_padding(char *format);
int		f_justifying(char *format);
int		handling(char *format);
int		store_fmats(const char *str, va_list args, char **fmated);
int		ft_printf(const char *str, ...);

#endif