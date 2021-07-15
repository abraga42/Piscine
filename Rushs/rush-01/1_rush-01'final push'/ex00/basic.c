/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:59:30 by adesgran          #+#    #+#             */
/*   Updated: 2021/07/11 21:45:34 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_tab(int **tab, int size)
{
	int	l;
	int	c;

	l = 0;
	while (l < size)
	{
		c = 0;
		while (c < size)
		{
			ft_putchar(tab[l][c] + '0');
			if (c < size - 1)
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
	free(tab);
}

int	ft_check_value(int **tab, int index, int size)
{
	int	col;
	int	row;
	int	init_col;
	int	init_row;

	col = index % size;
	row = index / size;
	init_col = col;
	init_row = row;
	while (row > 0)
	{
		if (tab[row - 1][init_col] == tab[init_row][init_col])
			return (0);
		row--;
	}
	while (col > 0)
	{
		if (tab[init_row][col - 1] == tab[init_row][init_col])
			return (0);
		col--;
	}
	return (1);
}
