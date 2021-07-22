/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:04:17 by abraga            #+#    #+#             */
/*   Updated: 2021/07/22 14:37:45 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_wordlen(char *str, char *charset, int start)
{
	int	count;

	count = 0;
	while (str[start] && ft_is_charset(str[start], charset) == 1)
		start++;
	while (str[start] && ft_is_charset(str[start], charset) == 0)
	{
		start++;
		count++;
	}
	return (count);
}

int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	count2;

	i = 0;
	count2 = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) == 0)
		{
			count2++;
			while (str[i] && ft_is_charset(str[i], charset) == 0)
				i++;
		}
		else
			i++;
	}
	printf("la valeur sans separateur : %d\n", count2);
	return (count2);
}

char	*ft_strndup(char *str, int start, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	while (str[start] && i < size)
	{
		tmp[i] = str[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		count2;
	char	**tab;

	i = 0;
	j = 0;
	count2 = ft_wordcount(str, charset);
	tab = NULL;
	tab = malloc(sizeof(char *) * (count2 + 1));
	if (!tab)
		return (NULL);
	while (str[i] && j < count2)
	{
		if (ft_is_charset(str[i], charset) == 0)
		{
			tab[j++] = ft_strndup(str, i, ft_wordlen(str, charset, i));
			while (str[i] && ft_is_charset(str[i], charset) == 0)
				i++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
