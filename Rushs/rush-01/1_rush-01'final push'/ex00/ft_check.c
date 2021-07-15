/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravoaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:11:47 by aravoaha          #+#    #+#             */
/*   Updated: 2021/07/11 23:34:49 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	ft_check_value(int **tab, int index, int size);

int	ft_check_cond_colup(int **cond, int **tab, int index, int size)
{
	int	max;
	int	count;
	int	n;

	max = 0;
	count = 0;
	n = 0;
	while (n < index / size)
	{
		if (tab[n][index % size] > max)
		{
			count++;
			max = tab[n][index % size];
		}
		n++;
	}
	if (count <= cond[0][index % size])
		return (1);
	else
		return (0);
}

int	ft_check_cond_rowleft(int **cond, int **tab, int index, int size)
{
	int	max;
	int	count;
	int	n;

	max = 0;
	count = 0;
	n = 0;
	while (n < index % size)
	{
		if (tab[index / size][n] > max)
		{
			count++;
			max = tab[index / size][n];
		}
		n++;
	}
	if (count <= cond[2][index / size])
		return (1);
	else
		return (0);
}

int	ft_check_cond_coldown(int **cond, int **tab, int index, int size)
{
	int	max;
	int	count;
	int	n;

	max = 0;
	count = 0;
	n = size - 1;
	while (n >= 0)
	{
		if (tab[n][index % size] > max)
		{
			count++;
			max = tab[n][index % size];
		}
		n--;
	}
	if (count <= cond[1][index % size])
		return (1);
	else
		return (0);
}

int	ft_check_cond_rowright(int **cond, int **tab, int index, int size)
{
	int	max;
	int	count;
	int	n;

	max = 0;
	count = 0;
	n = size - 1;
	while (n >= 0)
	{
		if (tab[index / size][n] > max)
		{
			count++;
			max = tab[index / size][n];
		}
		n--;
	}
	if (count <= cond[3][index / size])
		return (1);
	else
		return (0);
}

int	ft_check(int **cond, int **tab, int index, int size)
{
	{
		if (ft_check_value(tab, index, size) == 0)
			return (0);
		if (ft_check_cond_colup(cond, tab, index, size) == 0)
			return (0);
		if (ft_check_cond_rowleft(cond, tab, index, size) == 0)
			return (0);
	}
	if (index / size == size - 1)
	{
		if (ft_check_cond_coldown(cond, tab, index, size) == 0)
			return (0);
	}
	if (index % size == size - 1)
	{
		if (ft_check_cond_rowright(cond, tab, index, size) == 0)
			return (0);
	}
	return (1);
}
