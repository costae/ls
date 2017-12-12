/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file26.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:12 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putnn42(long long nb, int nbl)
{
	if (g_tab.prec <= nbl)
	{
		ft_putchar(' ');
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		ft_putchar(' ');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void		ft_putnn43(long long nb, int nbl)
{
	if (g_tab.prec <= nbl)
	{
		ft_putchar('+');
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		ft_putchar('+');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void		ft_putnn4(long long nb, int nbl)
{
	if ((nb >= 0 && g_tab.plus == 0) || (nb < 0 && g_tab.plus == 1))
	{
		if (g_tab.space == 0)
			ft_putnn41(nb, nbl);
		else if (g_tab.space == 1)
			ft_putnn42(nb, nbl);
	}
	else if (nb >= 0 && g_tab.plus == 1)
		ft_putnn43(nb, nbl);
	else
	{
		if (g_tab.prec <= nbl)
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		else
		{
			ft_putchar('-');
			ft_putnch('0', g_tab.prec - (nbl) + 1);
			ft_write(ft_itoa(FT_ABS(nb)), ft_strlen(ft_itoa(FT_ABS(nb))));
		}
	}
}

void		ft_putnn51(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	else
	{
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		ft_putnch(' ', g_tab.width - g_tab.prec);
	}
}

void		ft_putnn52(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_putchar(' ');
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		ft_putchar(' ');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		ft_putnch(' ', g_tab.width - g_tab.prec - 1);
	}
}
