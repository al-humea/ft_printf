/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:16:51 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/10 17:35:20 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

/*
** TO FIX :
** WIDTH(with 0)/PREC WITH NEGATIVE VALUES
** LENGHT MODIFIERS WITH NULL VARIABLES
*/

int main(void)
{
	printf("---------PRINTF----------\n");
	printf("{%05.*d}\n", -15, 42);
	printf("--------FT_PRINTF--------\n");
	ft_printf("{%05.*d}\n", -15, 42);
	printf("-------------------------.\n");
}