/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:56:39 by al-humea          #+#    #+#             */
/*   Updated: 2021/01/19 19:02:46 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//checks if format is valid
int	fmat_valider(const char *str)
{
	int	i;
// starts at 1 to skip first %
	i = 1;
	if (!str || !str[i])
		return (-1);
	while (str[i])
	{
		if (ft_strsrc("dciuspxX %-*0123456789", str[i]))
		{
			if (ft_strsrc("dciuspxX%", str[i]))
				return(i+1);
			i++;
			continue ;
		}
		return (-1);
	}
	return (i+1);
}
//checks if formatS are valid using fmat valider returns the total number of % -1 if error in formats
int	valid_fmat(const char *str)
{
	int	i;
	int	j;
	int	fmat_count;

	i = 0;
	j = 0;
	fmat_count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((j = fmat_valider(&str[i])) == -1)
				return (-1);
			fmat_count++;
			i += j;
			continue ;
		}
		i++;
	}
	return (fmat_count);
}
//stores converted formats in fmated
int	store_fmats(const char *str, va_list args, char **fmated)
{
	int i;
	int	ret;

	if ((ret = valid_fmat(str)) == -1)
		return (-1);
	if (!(fmated = malloc(sizeof(char *) * (ret + 1))))
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i += handling((char *)&str[i], args, fmated); // += add to skip read format
			continue ;
		}
		i++;
	}
	fmated[ret] = NULL;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i; // initialise pour avoir un i pr le display final (while)
	int		fmat_count;
	va_list	args;
	char	**fmated;

	i = 0;
	fmat_count = 0;
	va_start(args, str);
	if((store_fmats(str, args, fmated)) == -1)
		return (-1);
	va_end(args);
	//15 lignes
	//while display everything 
	//free fmated
	return (i);//+ formats lengths
}