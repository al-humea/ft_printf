/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:56:39 by al-humea          #+#    #+#             */
/*   Updated: 2021/03/02 20:14:30 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	skipformat(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strsrc("dciuspxX%", str[i]))
			return (i + 1);
		i++;
	}
	return (0);
}

/*
**checks if format is valid
*/

int	fmat_valider(const char *str)
{
	int	i;

	i = 1;
	if (!str || !str[i])
		return (-1);
	while (str[i])
	{
		if (ft_strsrc("dciuspxX%.-*0123456789", str[i]))
		{
			if (ft_strsrc("dciuspxX%", str[i]))
				return (++i);
			i++;
			continue ;
		}
		return (-1);
	}
	return (i + 1);
}

/*
** checks if formatS are valid using fmat valider returns
** the total number of % -1 if error in formats
*/

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

/*
**stores converted formats in fmated
*/

int	store_fmats(const char *str, va_list args, char ***fmated)
{
	int	i;
	int	j;
	int	ret;

	if ((ret = valid_fmat(str)) == -1)
		return (-1);
	if (!(*fmated = malloc(sizeof(char *) * (ret + 1))))
		return (-1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i += handling((char *)&str[i], args, &(*fmated)[j]);
			j++;
			continue ;
		}
		i++;
	}
	(*fmated)[ret] = NULL;
	return (0);
}

/*
** ADD THE SIZE FMATED ELEMENTS TO RETURN VALUE
*/

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	args;
	char	**fmated;

	fmated = NULL;
	i = 0;
	j = 0;
	va_start(args, str);
	if ((store_fmats(str, args, &fmated)) == -1)
		return (-1);
	va_end(args);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += skipformat(&str[i]);
			ft_putstr_fd(fmated[j], 1);
			free(fmated[j++]);
			continue ;
		}
		write(1, &str[i++], 1);
	}
	free(fmated);
	return (i);
}
