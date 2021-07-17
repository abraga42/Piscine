/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:24:35 by abraga            #+#    #+#             */
/*   Updated: 2021/07/16 14:55:02 by abraga           ###   ########.fr       */
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
		c++;
	}
	write (1, "\n", 1);
}

int	ft_check(char *str)
{
	int	a;

	a = 0;
	while (!(str[a] == ' ' || str[a] == '\t' )
	{
		ft_putstr(&str[a]);
		a++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc >= 2)
	{
		ft_check(argv[i]);
		i++;
	}
	return (0);
}
