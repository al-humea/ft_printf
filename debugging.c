/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:16:51 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/05 19:15:46 by al-humea         ###   ########.fr       */
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
	printf("|%.d|\n", 1);
	printf("--------FT_PRINTF--------\n");
	ft_printf("|%.d|\n", 1);
	printf("-------------------------\n");
}