/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:11:59 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/27 12:35:42 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	void *ptr;

	ptr = malloc(sizeof(int));
	printf("ft_printf : %d\n", ft_printf("%-0*.*s, %*.5s || %-5.2d", "test str", 10, 7, "hahalol", 7, 1));
	free(ptr);
	return (0);
}