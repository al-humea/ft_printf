/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:49:44 by al-humea          #+#    #+#             */
/*   Updated: 2021/02/15 20:45:27 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	printf("testing out ptr : |%10.1p|\n\n", NULL);
	ft_printf("testing out ptr : |%10.1p|\n", NULL);
	ft_printf("-----------P------------\n");
	printf("testing out strings : |%10s|\n\n", NULL);
	ft_printf("testing out strings : |%10s|\n", NULL);
	ft_printf("-----------S------------\n");
	printf("testing out ptr : |%16.3p|\n\n", "(nil)");
	ft_printf("testing out ptr : |%16.3p|\n", "(nil)");
	ft_printf("-----------P------------\n");
	printf("testing out strings : |%10.3s|\n\n", "(null)");
	ft_printf("testing out strings : |%10.3s|\n", "(null)");
	ft_printf("-----------S------------\n");
	return (0);
}