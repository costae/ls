/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:40 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						ft_nblen(long long int nb)
{
	int					i;
	long long int		n;

	i = 0;
	n = nb;
	if (nb < 0)
		i = 1;
	while (n /= 10)
		i++;
	return (i + 1);
}

void					ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

unsigned long long		itoa_isnegative(long long int n)
{
	unsigned long long	un;

	un = 0;
	if (n < 0)
	{
		un = n * -1;
	}
	return (un);
}

char					*ft_stritoa(char *str, int len, unsigned long long unl,
			int negative)
{
	while (len--)
	{
		str[len] = unl % 10 + '0';
		unl = unl / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char					*ft_itoa(long long int n)
{
	int					len;
	unsigned long long	un;
	unsigned long long	unl;
	int					negative;
	char				*str;

	len = 2;
	negative = 0;
	if (n < 0)
	{
		un = itoa_isnegative(n);
		negative = 1;
	}
	else
		un = n;
	unl = un;
	while (un /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	str = ft_stritoa(str, len, unl, negative);
	return (str);
}
