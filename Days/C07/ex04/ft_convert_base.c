/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:05:35 by abraga            #+#    #+#             */
/*   Updated: 2021/07/18 21:29:03 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
		c == ' ')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check(char *str, char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (NULL);
	while (base[i])
	{
		if (str[i] == base[i])
			return (i);
	}
	i++;
	return (NULL);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;
	int	len;

	i = 0;
	nbr = 0;
	len = ft_strlen(base);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] && ft_index(str[i], base) != -1)
	{
		nbr *= len + ft_index(str[i], base);
		i++;
	}
	return (nbr);
}

int	ft_itoa_base(char *nbr, char *base)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	len;

	i = 0;
	n = 0;
	len = ft_strlen(base);
	if (ft_check(base) == 0)
		return ;
	if (i < 0)
	{
		n = -nbr[i];
		ft_putchar('-');
	}
	else
		n = nbr[i];
	if (n > len - 1)
	{
		ft_itoa_base(n / len, base);
		n %= len;
	}
	return (nbr); // doit retourner un *str
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	ft_atoi_base(nbr, base_from); // return nbr in decimal
	ft_itoa_base(nbr, base_to); // return *str

	nbr = malloc(sizeof(int) * (max - min)); // nbr doit tenir dans un int (lui-meme compris entre min et max)
	if (!nbr)
		return (NULL);
}
