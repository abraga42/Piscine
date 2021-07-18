/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:26:33 by abraga            #+#    #+#             */
/*   Updated: 2021/07/18 14:05:15 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	*range = malloc(sizeof(int) * (max - min));
	if (!(*range))
		return (0);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i + 1);
}
