/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:19:36 by abraga            #+#    #+#             */
/*   Updated: 2021/07/15 11:51:04 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{	
		write (1, &str[c], 1);
		c++;
	}
		write (1, "\n", 1);
}

void	ft_params(char **argv)
{
	int	u;

	u = 1;
	while (argv[u])
	{
		ft_putstr(argv[u]);
		u++;
	}
}

int		main (int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		ft_params(argv);
	}
	return (0);
}
