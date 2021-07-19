/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:05:33 by abraga            #+#    #+#             */
/*   Updated: 2021/07/20 00:26:53 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c);
int	ft_strlen(char *str);
int	ft_check(char *str, char *base);
int	ft_index(char c, char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_isnegative(int nbr, char *base, int len, int baselen)
{
	long	tmp;
	char	*str;

	tmp = nbr;
	temp *= -1;
	str = (char *) malloc(sizeof(char) * (len + 2));
	str[0] = '-';
	str[len + 1] = '\0';
	while (tmp != 0)
	{
		str[len] = base[tmp % baselen];
	}
}
