/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:31 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void					ft_putstr3(char *str)
{
	if (g_tab.prec == 0 && g_tab.punct == 1)
		ft_putnch(' ', g_tab.width);
	else if (g_tab.width && g_tab.minus == 0 && g_tab.htag == 0)
		ft_putxx1(str);
	else if (g_tab.prec && g_tab.width <= g_tab.prec && g_tab.htag == 0)
		ft_putxx2(str);
	else if (g_tab.minus && g_tab.htag == 0)
		ft_putxx3(str);
	else if (g_tab.htag)
		ft_putxx4(str);
	else
		ft_putstr(str);
}

char					*ft_utoa(unsigned long long int n)
{
	unsigned long long	tmpn;
	int					len;
	int					negative;
	char				*str;

	tmpn = n;
	len = 2;
	negative = 0;
	while (n /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = tmpn % 10 + '0';
		tmpn = tmpn / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
