/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillwith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:56:55 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/31 12:15:35 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fillwith(char *dst, char c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dst[i] = c;
		i++;
	}
	dst[i] = '\0';
	return ;
}
