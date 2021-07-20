/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:05:33 by abraga            #+#    #+#             */
/*   Updated: 2021/07/20 19:18:20 by abraga           ###   ########.fr       */
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

	tmp = nbr;
	tmp *= -1;
	str = (char *) malloc(sizeof(char) * (len + 2));
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
		return(1);
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
	if (nbr < 0)
	{
		return (ft_isnegative(nbr, base, len, baselen));
	}
	else
	{
		str = (char *) malloc(sizeof(char) * len + 1);
		str[len] = '\0';
		while (nbr != 0)
		{
			str[len - 1] = base[nbr % baselen];
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

	if (ft_check_base(base_from) == 0 || ft_check_base(base_to) == 0)
		return (0);
	else
	{
		i = ft_atoi_base(nbr, base_from);
		str = ft_itoa_base(i, base_to);
	}
	return (str);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	printf("%s\n", ft_itoa_base(42, argv[2]));
	
//	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
}
