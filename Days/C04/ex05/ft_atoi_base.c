/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:22:51 by abraga            #+#    #+#             */
/*   Updated: 2021/07/14 13:15:44 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_space(char w)
{
	if (w == '\t' || w == '\n' || w == '\v' || w == '\f' || w == '\r'
		|| w == ' ')
		return (1);
	else
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

int	ft_base_check(char *str, char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (-1);
	while (base[i])
	{
		if (str[i] == base[i])
			return (i);
	}
	i++;
	return (-1);
}

int	ft_index_base(char x, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (x == base[i])
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
	int	baselen;

	i = 0;
	mult = 1;
	nbr = 0;
	baselen = ft_strlen(base);
	while (ft_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = mult * -1;
		i++;
	}
	while (str[i] && ft_index_base(str[i], base) != -1)
	{
		nbr = nbr * baselen + ft_index_base(str[i], base);
		i++;
	}
	return (nbr * mult);
}
