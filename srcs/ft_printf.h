/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:17:51 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/28 20:08:57 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
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
//utils mostly to remove
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	ft_strsrc(const char *str, int src); //To save
void	ft_fillwith(char *dst, char c, int dst_size); //To save
long unsigned int	ft_atolu(const char *str);//To save
char	*ft_chardup(char c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int nbr);
char	*ft_utoa(unsigned int n);
char	*ft_lutoa(unsigned long nbr);
char	*ft_lutox(unsigned long nbr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
//tostr
void	hexaflags(t_flags *flags);
void	addprecision(t_flags *flags, int size);
void	addwidth(t_flags *flags, int size);
//flags
void	flags_bzero(t_flags *flags);
int		f_prec(const char *str, va_list args);
int		f_width(const char *str, va_list args);
char	f_padding(const char *str);
int		f_justifying(const char *str);
void	*fmat_arg(char type, va_list args);
void	f_fmat(char *str, va_list args, t_flags *flags);
int		get_flags(t_flags *flags, char *format, va_list args);
//main
int		handling(char *format, va_list args, char **fmated);
int		store_fmats(const char *str, va_list args, char **fmated);
int		ft_printf(const char *str, ...);

#endif