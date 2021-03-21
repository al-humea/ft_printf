/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chardup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:58:43 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/21 19:02:10 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_chardup(char c)
{
	char	*dup;

	if (!(dup = malloc(sizeof(char) * 2)))
		return (NULL);
	dup[0] = c;
	dup[1] = '\0';
	return (dup);
}
