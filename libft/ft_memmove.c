/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:32:08 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/21 15:35:37 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ndst;
	const char	*nsrc;

	if (!dst && !src)
		return (NULL);
	ndst = dst;
	nsrc = src;
	if (ndst < nsrc)
	{
		while (len--)
			*ndst++ = *nsrc++;
	}
	else
	{
		ndst += (len - 1);
		nsrc = (char *)nsrc + (len - 1);
		while (len--)
			*ndst-- = *nsrc--;
	}
	return (dst);
}
