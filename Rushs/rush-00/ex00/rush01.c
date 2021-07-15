/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:01:05 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/04 22:12:05 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

// fontion de conditions permettamt a int a d'ecrire les bons symboles
void	conditions(int	a, int	b, int	x, int	y)
{
	if ((a == x && y == 1) || (b == y && x == 1))
		ft_putchar('\\');
	else if ((a == 1 && b == 1) || (a == x && b == y))
		ft_putchar('/');
	else if ((a == x && b == 1) || (a == 1 && b == y))
		ft_putchar('\\');
	else if ((b > 1 && b < y) && (a > 1 && a < x))
		ft_putchar(' ');
	else
		ft_putchar('*');
}

// int a ecrit les lignes selon les conditions et son max x
// int b permet de sauter une ligne a chaques iterations et de reset int a
void	rush01(int	x, int	y)
{
	int	a;
	int	b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			if (x == 1 && y == 1)
			{
				ft_putchar('/');
				break ;
			}
			conditions(a, b, x, y);
			a++;
		}
		b++;
		ft_putchar('\n');
	}
}
