/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:12:22 by al-humea          #+#    #+#             */
/*   Updated: 2019/11/20 13:27:28 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_wsize(char const *str, char c, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (str[index] != c && str[index])
	{
		i++;
		index++;
	}
	return (i);
}

static long	get_index(char const *str, char c, unsigned int wn)
{
	long	i;
	long	index;
	int		done;

	i = 0;
	index = 0;
	done = 0;
	while (str[i])
	{
		if (str[i] != c && !done)
		{
			done = 1;
			index++;
		}
		if (str[i] == c)
			done = 0;
		if (index == wn)
			return (i);
		i++;
	}
	return (0);
}

static long	nb_words(const char *str, char c)
{
	long	i;
	long	nb;
	int		done;

	i = 0;
	nb = 0;
	done = 0;
	while (str[i])
	{
		if (str[i] != c && !done)
		{
			done = 1;
			nb++;
		}
		if (str[i] == c)
			done = 0;
		i++;
	}
	return (nb);
}

static char	**free_tab(char **tab, long size)
{
	long	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab);
}

char		**ft_split(char const *str, char c)
{
	long	i;
	long	nb;
	long	index;
	char	**tab;

	if (!str)
		return (NULL);
	nb = nb_words(str, c);
	if (!(tab = malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		index = get_index(str, c, i + 1);
		if (!(tab[i] = malloc(get_wsize(str, c, index) + 1)))
			return (free_tab(tab, i));
		ft_strlcpy(tab[i], &str[index], get_wsize(str, c, index) + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
