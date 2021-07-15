/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:00:13 by abraga            #+#    #+#             */
/*   Updated: 2021/07/14 13:10:55 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[i] && base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	len;

	n = 0;
	len = ft_strlen(base);
	if (ft_base_check(base) == 0)
		return ;
	if (nbr < 0)
	{
		n = -nbr;
		ft_putchar('-');
	}
	else
		n = nbr;
	if (n > len - 1)
	{
		ft_putnbr_base(n / len, base);
		n %= len;
	}
	ft_putchar(base[n]);
}
