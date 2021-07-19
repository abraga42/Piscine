/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:05:35 by abraga            #+#    #+#             */
/*   Updated: 2021/07/20 00:26:51 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		return (0);
	while (base[i])
	{
		if (str[i] == base[i])
			return (i);
	}
	i++;
	return (0);
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
	int	mult;
	int	nbr;
	int	len;

	i = 0;
	mult = 1;
	nbr = 0;
	len = ft_strlen(base);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = mult * -1;
		i++;
	}
	while (str[i] && ft_index(str[i], base) != -1)
	{
		nbr *= len + ft_index(str[i], base);
		i++;
	}
	return (nbr * mult);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long	i;
	long	count;
	long	n;
	long	len;
	char	*str = NULL;

	i = nbr;
	count = 0;
	n = 0;
	len = ft_strlen(base);
	while (i != 0)
	{
		i = i / len;
		count++;
	}
	else
	{
		str = malloc(sizeof(char) * count + 1);
		str[count] = '\0';
	}
	while (nbr != 0)
	{
		str[count - 1] = (nbr % len) + 48;
		nbr = nbr / len;
		count--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

	// nbr doit tenir dans un int (lui-meme compris entre min et max)

	// retourne le res de la conversion de *nbr de base_from en base__to

#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_atoi_base("80", "0123456789abcdef"));
}
