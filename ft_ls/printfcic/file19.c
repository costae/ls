/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file19.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:47 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putvv53(unsigned long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
	else
	{
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		ft_putnch(' ', g_tab.width - g_tab.prec - 1);
	}
}

void	ft_putvv5(unsigned long long nb, int nbl)
{
	if (g_tab.plus == 0)
	{
		if (g_tab.space == 0)
			ft_putvv51(nb, nbl);
		else if (g_tab.space == 1)
			ft_putvv52(nb, nbl);
	}
	else if (g_tab.plus == 1)
		ft_putvv53(nb, nbl);
	else
	{
		if (g_tab.width <= nbl)
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		else
		{
			ft_putchar('-');
			ft_putnch('0', g_tab.prec - nbl);
			ft_write(ft_utoa(FT_ABS(nb)), ft_strlen(ft_utoa(FT_ABS(nb))));
			ft_putnch(' ', g_tab.width - g_tab.prec);
		}
	}
}

void	ft_putvv6(unsigned long long nb, int nbl)
{
	if (g_tab.plus == 0)
	{
		if (g_tab.space == 1)
		{
			ft_putnch(' ', g_tab.width - nbl - 1);
			ft_putchar(' ');
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		}
		else
		{
			ft_putnch(' ', g_tab.width - nbl);
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		}
	}
	else if (g_tab.plus == 1)
	{
		ft_putnch(' ', g_tab.width - nbl);
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
}

void	ft_putvv7(unsigned long long nb, int nbl)
{
	if (g_tab.plus == 0)
	{
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		ft_putnch(' ', g_tab.width - nbl);
	}
	else if (g_tab.plus == 1)
	{
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		ft_putnch(' ', g_tab.width - nbl - 1);
	}
}
