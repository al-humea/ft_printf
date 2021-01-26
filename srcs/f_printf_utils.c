/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:09 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/26 13:26:15 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//every fctions except ft_strsrc

int	ft_nbrlen(unsigned long nbr)
{
	int i;

	i = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i + 1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_chardup(char c)
{
	char	*dup;

	if (!(dup = malloc(2)))
		return (NULL);
	dup[0] = c;
	dup[1] = '\0';
	return (dup);
}

char	*ft_strdup(const char *s1)
{
	char	*nstr;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	if (!(nstr = malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		nstr[i] = s1[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
// Only one not to delete
char	ft_strsrc(const char *str, int src)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == src)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					mlt;
	int					nbr;
	unsigned int		i;

	i = 0;
	nbr = 0;
	mlt = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			mlt *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * mlt);
}

static void	nbtoright1(char *str, int m)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	str[i + 1] = '\0';
	while (i > m)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[i] = 0;
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		m;
	long	nb;

	nb = nbr;
	m = 0;
	if (!(str = malloc(12)))
		return (NULL);
	if (nb < 0)
	{
		str[m] = '-';
		nb *= -1;
		m++;
	}
	str[m] = '\0';
	while (nb > 9)
	{
		nbtoright1(str, m);
		str[m] = (nb % 10) + 48;
		nb /= 10;
	}
	nbtoright1(str, m);
	str[m] = nb + 48;
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	char			*p;
	int				size;
	unsigned int	x;

	x = n;
	size = 0;
	while (x > 10)
	{
		x /= 10;
		size++;
	}
	if (!(p = (char *)malloc(sizeof(p) * (size + 1))))
		return (NULL);
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 10;
			p[size] = 48 + x;
			n = n / 10;
			size--;
		}
	}
	return (p);
}

static void	nbtoright(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	str[i + 1] = '\0';
	while (i > 0)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[i] = 0;
}

char		*ft_lutoa(unsigned long nbr)
{
	char *str;

	if (!(str = malloc(ft_nbrlen(nbr) + 1)))
		return (NULL);
	str[0] = 0;
	while (nbr >= 10)
	{
		nbtoright(str);
		str[0] = nbr % 10 + 48;
		nbr /= 10;
	}
	nbtoright(str);
	str[0] = nbr % 10 + 48;
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	unsigned int	i;
	unsigned int	src_len;

	if (!dst || !src)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	if (dst_size == 0)
		return ((size_t)src_len);
	while (i < (dst_size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ((size_t)src_len);
}

void	ft_fillwith(char *dst, char c, int dst_size)
{
	int i;

	i = 0;
	while (i < dst_size)
	{
		dst[i] = c;
		i++;
	}
	dst[i] = '\0';
	return ;
}