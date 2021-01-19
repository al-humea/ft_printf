/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:51 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/19 19:02:44 by al-humea         ###   ########.fr       */
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
	char	type;
	int		just;
	char	pad;
	int		width;
	int		prec;
	void	*data;
} t_flags;

int		ft_atoi(const char *str);
char	ft_strsrc(const char *str, int src);
int		f_prec(char *format);
int		f_width(char *format);
char	f_padding(char *format);
int		f_justifying(const char *str);
int		handling(char *format, va_list args, char **fmated);
int		store_fmats(const char *str, va_list args, char **fmated);
int		ft_printf(const char *str, ...);

#endif