/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:19:27 by abraga            #+#    #+#             */
/*   Updated: 2021/07/07 19:14:53 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int	ft_str_is_alpha(char *str)
{
	if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
		{
			str[a] = str[a] + 32;
		}
		a++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	a;

	a = 0;
	ft_strlowcase(str);
	while (str[a])
	{
		if (a == 0 && str[a] >= 'a' && str[a] <= 'z')
		{
			str[a] = str[a] - 32;
		}
		else if (a > 0 && ft_str_is_alpha(&str[a - 1]) == 0 && ft_str_is_numeric(&str[a - 1]) == 0 && str[a] >= 'a' && str[a] <= 'z')
		{
			str[a] = str[a] - 32;
		}
		a++;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	write(1, str, l);
}

int		main()
{
	char c[] = "      salut, coMMent tu vAs ? 42mOts quArAnTe-dEux; cinQuante+et+un";
	printf("%s\n", c);
	ft_putstr(ft_strcapitalize(c));
}

