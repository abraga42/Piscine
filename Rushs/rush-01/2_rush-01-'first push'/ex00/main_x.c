/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:28:46 by adesgran          #+#    #+#             */
/*   Updated: 2021/07/11 23:45:25 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

void	ft_put_tab(int **tab, int size);
int		ft_strlen(char *str);
int		ft_print_tab(int **cond, int **tab, int index, int size);

int	ft_check_input(char *input, int size)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (ft_strlen(input) != size * 8 - 1)
		return (0);
	while (input[i])
	{
		if (i % 2 == 1 && input[i] != ' ')
			return (0);
		else if (i % 2 == 0 && (input[i] < '1' || input[i] > size + '0'))
			return (0);
		else if (i % 2 == 0)
			n++;
		i++;
	}
	if (n != 4 * size)
		return (0);
	return (1);
}

int	**ft_create_cond_tab(int size, char *str)
{
	int	row;
	int	col;
	int	**cond;

	cond = malloc(sizeof(*cond) * 4);
	if (cond == NULL)
		return (NULL);
	row = 0;
	while (row < 4)
	{
		cond[row] = malloc(sizeof(int) * size);
		if (cond[row] == NULL)
			return (NULL);
		col = 0;
		while (col < size)
		{
			cond[row][col] = str[2 * (row * size + col)] - '0';
			col++;
		}
		row++;
	}
	return (cond);
}

int	ft_check_cond(int **cond, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (cond[0][i] + cond[1][i] > size + 1 || cond[0][i] + cond[1][i] < 3)
			return (0);
		if (cond[2][i] + cond[3][i] > size + 1 || cond[2][i] + cond[3][i] < 3)
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(char **argv)
{
	int	**tab;
	int	i;
	int	size;
	int	**cond;

	size = (ft_strlen(argv[1]) + 1) / 8;
	if (ft_check_input(argv[1], size) && size > 2 && size < 10)
		cond = ft_create_cond_tab(size, argv[1]);
	else
		return (0);
	tab = malloc(sizeof(*tab) * size);
	if (tab == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(sizeof(int) * size);
		if (tab[i] == NULL)
			return (0);
		i++;
	}
	if (ft_print_tab(cond, tab, 0, size))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_solve(argv) == 0)
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
