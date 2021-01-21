/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:11:59 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/21 19:01:34 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	void *ptr;

	ptr = malloc(sizeof(int));
	printf("ft_printf : %d\n", ft_printf("test str : %-052.3s\ntest int : %052.1d\ntest ptr : %10p\n", "a", 52, ptr));
	free(ptr);
	return (0);
}