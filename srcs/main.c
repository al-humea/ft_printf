/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:11:59 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/25 23:34:17 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	void *ptr;

	ptr = malloc(sizeof(int));
	printf("ft_printf : %d\n", ft_printf("test str : |%-010s|\n", "|test str|"));
	free(ptr);
	return (0);
}