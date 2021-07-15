/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:25:59 by abraga            #+#    #+#             */
/*   Updated: 2021/07/15 17:08:28 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		write (1, &c, 1);
	}
	write (1, "\n", 1);
}

void	ft_swap(char *a, char *b)
{
	char	*temp;

	temp = a;
	a = b;
	b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main (int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	if (argc >= 2)
	{
		if (i 0 > j)
		{
			ft_swap(argv[i], argv[j]);
		}
		else
			ft_strcmp(argv[i], argv[j]);
		ft_putstr(argv[i]);
	}
	return (0);
}
