/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file25.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:05 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putnn31(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		ft_putnch(' ', g_tab.width - g_tab.prec);
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void		ft_putnn32(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_putchar(' ');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		ft_putnch(' ', g_tab.width - g_tab.prec - 1);
		ft_putchar(' ');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void		ft_putnn33(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_putchar('+');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		ft_putnch(' ', g_tab.width - g_tab.prec - 1);
		ft_putchar('+');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void		ft_putnn3(long long nb, int nbl)
{
	if ((nb >= 0 && g_tab.plus == 0) || (nb < 0 && g_tab.plus == 1))
	{
		if (g_tab.space == 0)
			ft_putnn31(nb, nbl);
		else if (g_tab.space == 1)
			ft_putnn32(nb, nbl);
	}
	else if (nb >= 0 && g_tab.plus == 1)
		ft_putnn33(nb, nbl);
	else
	{
		if (g_tab.width <= nbl)
		{
			ft_putchar('-');
			ft_putnch('0', g_tab.prec - nbl);
			ft_write(ft_itoa(nb / -1), ft_strlen(ft_itoa(FT_ABS(nb))));
		}
		else
		{
			ft_putnch(' ', g_tab.width - g_tab.prec - 1);
			ft_putchar('-');
			ft_putnch('0', g_tab.prec - nbl + 1);
			ft_write(ft_itoa(FT_ABS(nb)), ft_strlen(ft_itoa(FT_ABS(nb))));
		}
	}
}

void		ft_putnn41(long long nb, int nbl)
{
	if (g_tab.prec <= nbl)
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	else
	{
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}
