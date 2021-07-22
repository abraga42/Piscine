/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:05:46 by abraga            #+#    #+#             */
/*   Updated: 2021/07/22 14:39:10 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_obtain_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			len++;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (sep[j++])
			len++;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		index;
	int		i;
	int		j;
	int		len;

	len = ft_obtain_len(size, strs, sep);
	if (size == 0)
		return (dest = malloc(1));
	dest = malloc(sizeof(char) * (len + 1));
	index = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[index++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			dest[index++] = sep[j++];
		i++;
	}
	dest[index] = '\0';
	return (dest);
}
