/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file18.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:45 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putvv42(unsigned long long nb, int nbl)
{
	if (g_tab.prec <= nbl)
	{
		ft_putchar(' ');
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
	else
	{
		ft_putchar(' ');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
}

void	ft_putvv43(unsigned long long nb, int nbl)
{
	if (g_tab.prec <= nbl)
	{
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
	else
	{
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
}

void	ft_putvv4(unsigned long long nb, int nbl)
{
	if (g_tab.plus == 0)
	{
		if (g_tab.space == 0)
			ft_putvv41(nb, nbl);
		else if (g_tab.space == 1)
			ft_putvv42(nb, nbl);
	}
	else if (g_tab.plus == 1)
		ft_putvv43(nb, nbl);
	else
	{
		if (g_tab.prec <= nbl)
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		else
		{
			ft_putchar('-');
			ft_putnch('0', g_tab.prec - (nbl) + 1);
			ft_write(ft_utoa(FT_ABS(nb)), ft_strlen(ft_utoa(FT_ABS(nb))));
		}
	}
}

void	ft_putvv51(unsigned long long nb, int nbl)
{
	if (g_tab.width <= nbl)
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	else
	{
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		ft_putnch(' ', g_tab.width - g_tab.prec);
	}
}

void	ft_putvv52(unsigned long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_putchar(' ');
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
	else
	{
		ft_putchar(' ');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		ft_putnch(' ', g_tab.width - g_tab.prec - 1);
	}
}
