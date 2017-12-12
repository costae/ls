/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:40 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putvv1(unsigned long long nb)
{
	if (g_tab.htag == 0 && nb == 0)
		ft_putnch(' ', g_tab.width);
	else if (g_tab.htag == 1 || (g_tab.htag == 0 && nb != 0))
	{
		if (g_tab.minus == 0)
		{
			ft_putstr(ft_utoa(nb));
			ft_putnch(' ', g_tab.width - ft_strlen(ft_utoa(nb)));
		}
		else
		{
			ft_putnch(' ', g_tab.width - ft_strlen(ft_utoa(nb)));
			ft_putstr(ft_utoa(nb));
		}
	}
}

void	ft_putvv21(unsigned long long nb, int nbl)
{
	if (g_tab.width <= nbl)
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	else
	{
		ft_putnch(' ', g_tab.width - nbl);
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
}

void	ft_putvv22(unsigned long long nb, int nbl)
{
	if (g_tab.width <= nbl && g_tab.plus == 1)
	{
		ft_putchar(' ');
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
	else
	{
		if (g_tab.zero == 0)
		{
			ft_putnch(' ', g_tab.width - nbl - 1);
			ft_putchar(' ');
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		}
		else
		{
			ft_putnch(' ', g_tab.width - nbl - 1);
			ft_putchar('0');
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		}
	}
}

void	ft_putvv23(unsigned long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
	else
	{
		ft_putnch('0', g_tab.width - ft_strlen(ft_utoa(nb)));
		ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
}

void	ft_putvv2(unsigned long long nb, int nbl)
{
	if (g_tab.plus == 0)
	{
		if (g_tab.space == 0 && g_tab.zero == 0)
			ft_putvv21(nb, nbl);
		else if (g_tab.space == 1)
			ft_putvv22(nb, nbl);
		else if (g_tab.zero && g_tab.width)
		{
			if (g_tab.width <= nbl)
				ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
			else
			{
				ft_putnch('0', g_tab.width - ft_strlen(ft_utoa(nb)));
				ft_write(ft_utoa(FT_ABS(nb)), ft_strlen(ft_utoa(FT_ABS(nb))));
			}
		}
	}
	else if (g_tab.plus == 1)
		ft_putvv23(nb, nbl);
}
