/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:28:43 by abraga            #+#    #+#             */
/*   Updated: 2021/07/15 15:51:34 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		write (1, &str[c], 1);
		c++;
	}
	write (1, "\n", 1);
}

void	ft_rev_params(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		size;
	int		u;

	i = 1;
	size = argc;
	u = 1;
	while (i < size - i)
	{
		temp = argv[i];
		argv[i] = argv[size - i];
		argv[size - i] = temp;
		i++;
	}
	while (argv[u])
	{
		ft_putstr(argv[u]);
		u++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		ft_rev_params(argc, argv);
	}
	return (0);
}
