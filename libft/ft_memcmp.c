/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:04:48 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/15 15:31:14 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dups1;
	unsigned char	*dups2;
	unsigned int	i;

	i = 0;
	dups1 = (unsigned char *)s1;
	dups2 = (unsigned char *)s2;
	while (i < n)
	{
		if (dups1[i] != dups2[i])
			return (dups1[i] - dups2[i]);
		i++;
	}
	return (0);
}
