/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:12:56 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/17 11:39:24 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstrl_fd(char *s, unsigned int l, int fd)
{
	unsigned int i;

	i = 0;
	while (i < l)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
