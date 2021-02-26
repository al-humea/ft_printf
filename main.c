/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:49:44 by al-humea          #+#    #+#             */
/*   Updated: 2021/02/25 15:17:36 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
	printf("this is a test |%s|.\n", "str");
	ft_printf("this is a test |%s|.\n", "str");
	return (0);
}