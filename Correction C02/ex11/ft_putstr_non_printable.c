/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:24:38 by abraga            #+#    #+#             */
/*   Updated: 2021/07/07 15:38:36 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		a;
	char	*tab;

	tab = "0123456789abcdef";
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] < 32 || str[a] > 126)
		{
			ft_putchar('\\');
			ft_putchar(tab[((unsigned char)str[a]) / 16]);
			ft_putchar(tab[((unsigned char)str[a]) % 16]);
		}
		else
		{
			ft_putchar(str[a]);
		}
		a++;
	}
}
