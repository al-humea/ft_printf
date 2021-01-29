/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:42:35 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/14 14:58:19 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int chr, size_t n)
{
	unsigned char		*dest;
	unsigned const char	*sorc;

	dest = dst;
	sorc = src;
	while (n--)
	{
		if (*sorc == (unsigned char)chr)
		{
			*dest = *sorc;
			return ((unsigned char *)dest + 1);
		}
		*dest++ = *sorc++;
	}
	return (NULL);
}
