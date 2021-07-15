/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:19:27 by abraga            #+#    #+#             */
/*   Updated: 2021/07/08 16:01:25 by abraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int		a;

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
	int		a;

	a = 0;
	ft_strlowcase(str);
	while (str[a])
	{
		if (str[a] >= 'a' && str[a] <= 'z')
		{
			if (str[a - 1] < 'a' || str[a - 1] > 'z')
			{
				if (str[a - 1] < 'A' || str[a - 1] > 'Z')
				{
					if (str[a - 1] < '0' || str[a - 1] > '9')
					{
						str[a] = str[a] - 32;
					}
				}
			}
		}
		a++;
	}
	return (str);
}
