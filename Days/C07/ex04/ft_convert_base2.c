/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:05:33 by abraga            #+#    #+#             */
/*   Updated: 2021/07/20 23:52:15 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c);
int	ft_strlen(char *str);
int	ft_check_base(char *base);
int	ft_index(char c, char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_isnegative(int nbr, char *base, int len, int baselen)
{
	long	tmp;
	char	*str;

	str = NULL;
	tmp = nbr;
	tmp *= -1;
	str = malloc(sizeof(char) * (len + 2));
	str[0] = '-';
	str[len + 1] = '\0';
	while (tmp != 0)
	{
		str[len] = base[tmp % baselen];
		tmp = tmp / baselen;
		len--;
	}
	return (str);
}

int	ft_int_len(int nbr, int baselen)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / baselen;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long	tmp;
	long	baselen;
	long	len;
	char	*str;

	tmp = nbr;
	baselen = ft_strlen(base);
	len = ft_int_len(nbr, baselen);
	str = NULL;
	if (nbr < 0)
		return (ft_isnegative(nbr, base, len, baselen));
	else
	{
		str = malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		str[len--] = '\0';
		while (nbr > 0)
		{
			str[len] = base[nbr % baselen];
			nbr = nbr / baselen;
			len--;
		}
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (ft_check_base(base_from) == 0 || ft_check_base(base_to) == 0)
		return (NULL);
	else
	{
		i = ft_atoi_base(nbr, base_from);
		if (i == 0)
		{
			str = malloc(sizeof(char) * 2);
			if (!str)
				return (NULL);
			str[0] = base_to[0];
			str[1] = '\0';
			return (str);
		}
		str = ft_itoa_base(i, base_to);
	}
	return (str);
}
