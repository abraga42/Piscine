/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:55:11 by abraga            #+#    #+#             */
/*   Updated: 2021/07/21 23:20:08 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (1);
		index++;
	}
	return (0);
}

int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_is_charset(str[i]) == 1)
			i++;
		if (str[i])
			count++;
		while (ft_is_charset(str[i]) == 0)
			i++;
	}
	return (count);
}

char	*ft_fill(int *tmp_i, char *str, char *charset)
{
	// 1. Compter le nb de char qu'il y aura a malloc pour chaque string
	// 2. Malloc un char *str
	// 3. Boucle remplissant le char *str
	// 4. Return (str)
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		index2;

	*tab = NULL;
	i = 0;
	index2 = 0;
	*tab = malloc(sizeof(char *) * 
}
