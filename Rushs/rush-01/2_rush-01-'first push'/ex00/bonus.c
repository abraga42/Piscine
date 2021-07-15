/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:22:34 by abraga            #+#    #+#             */
/*   Updated: 2021/07/11 21:45:45 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_check(int **cond, int **tab, int index, int size);
void	ft_put_tab(int **tab, int size);

int	ft_print_tab(int **cond, int **tab, int index, int size)
{
	int	col;
	int	row;
	int	i;

	if (cond == NULL)
		return (0);
	col = index % size;
	row = index / size;
	if (index == size * size)
	{
		ft_put_tab(tab, size);
		free(cond);
		return (1);
	}
	i = 0;
	while (++i <= size)
	{
		tab[row][col] = i;
		if (ft_check(cond, tab, index, size) == 1)
		{
			if (ft_print_tab(cond, tab, (index + 1), size) == 1)
				return (1);
		}
	}
	return (0);
}
