/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:20:04 by abraga            #+#    #+#             */
/*   Updated: 2021/07/14 11:19:18 by abraga           ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	i;
	int	mult;
	int	nbr;

	i = 0;
	mult = 1;
	nbr = 0;
	while (ft_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = mult * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * mult);
}
