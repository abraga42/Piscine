/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:00:11 by abraga            #+#    #+#             */
/*   Updated: 2021/07/15 11:27:59 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char **str)
{
	int	c;

	c = 0;
	while (str[0][c] != '\0')
	{
		write (1, &str[0][c], 1);
		c++;
	}
}

int	main (int argc, char **argv)
{
	(void) argc;
	(void) argv;
	if (argc >= 1)
		ft_putstr(argv);
	return (0);
}
