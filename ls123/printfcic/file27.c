/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file27.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:14 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putnn53(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_putchar('+');
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		ft_putchar('+');
		ft_putnch('0', g_tab.prec - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		ft_putnch(' ', g_tab.width - g_tab.prec - 1);
	}
}

void		ft_putnn5(long long nb, int nbl)
{
	if ((nb >= 0 && g_tab.plus == 0) || (nb < 0 && g_tab.plus == 1))
	{
		if (g_tab.space == 0)
			ft_putnn51(nb, nbl);
		else if (g_tab.space == 1)
			ft_putnn52(nb, nbl);
	}
	else if (nb >= 0 && g_tab.plus == 1)
		ft_putnn53(nb, nbl);
	else
	{
		if (g_tab.width <= nbl)
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		else
		{
			ft_putchar('-');
			ft_putnch('0', g_tab.prec - nbl);
			ft_write(ft_itoa(FT_ABS(nb)), ft_strlen(ft_itoa(FT_ABS(nb))));
			ft_putnch(' ', g_tab.width - g_tab.prec);
		}
	}
}

void		ft_putnn6(long long nb, int nbl)
{
	if (g_tab.plus == 0 || (nb < 0 && g_tab.plus == 1))
	{
		if (g_tab.space == 1 && nb >= 0)
		{
			ft_putnch(' ', g_tab.width - nbl - 1);
			ft_putchar(' ');
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
		else
		{
			ft_putnch(' ', g_tab.width - nbl);
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
	}
	else if (nb >= 0 && g_tab.plus == 1)
	{
		ft_putnch(' ', g_tab.width - nbl - 1);
		ft_putchar('+');
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void		ft_putnn7(long long nb, int nbl)
{
	if (g_tab.plus == 0 || (nb < 0 && g_tab.plus == 1))
	{
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		ft_putnch(' ', g_tab.width - nbl);
	}
	else if (nb >= 0 && g_tab.plus == 1)
	{
		ft_putchar('+');
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		ft_putnch(' ', g_tab.width - nbl - 1);
	}
}

void		ft_putnn8(long long nb, int nbl)
{
	(void)nbl;
	if (g_tab.plus == 0 || (nb < 0 && g_tab.plus == 1))
	{
		if (g_tab.space == 1 && nb >= 0 && (g_tab.spec == 'd'
					|| g_tab.spec == 'D' || g_tab.spec == 'i'))
		{
			ft_putchar(' ');
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
		else
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else if (g_tab.plus == 1 && nb >= 0)
	{
		if (nb < 4000000)
		{
			ft_putchar('+');
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
		else
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}
