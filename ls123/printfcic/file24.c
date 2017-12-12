/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file24.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:03 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnn1(long long nb)
{
	if (g_tab.htag == 0 && nb == 0)
		ft_putnch(' ', g_tab.width);
	else if (g_tab.htag == 1 || (g_tab.htag == 0 && nb != 0))
	{
		if (g_tab.minus == 0)
		{
			ft_putstr(ft_itoa(nb));
			ft_putnch(' ', g_tab.width - ft_strlen(ft_itoa(nb)));
		}
		else
		{
			ft_putnch(' ', g_tab.width - ft_strlen(ft_itoa(nb)));
			ft_putstr(ft_itoa(nb));
		}
	}
}

void	ft_putnn21(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	else
	{
		ft_putnch(' ', g_tab.width - nbl);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void	ft_putnn22(long long nb, int nbl)
{
	if (g_tab.width <= nbl && g_tab.plus == 1)
	{
		ft_putchar(' ');
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
	else
	{
		if (g_tab.zero == 0)
		{
			ft_putnch(' ', g_tab.width - nbl - 1);
			ft_putchar(' ');
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
		else
		{
			ft_putnch(' ', g_tab.width - nbl - 1);
			ft_putchar('0');
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
	}
}

void	ft_putnn23(long long nb, int nbl)
{
	if (g_tab.width <= nbl)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
		else if (nb > 0)
		{
			ft_putchar('+');
			ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
		}
	}
	else
	{
		nb < 0 ? ft_putchar('-') : ft_putchar('+');
		ft_putnch('0', g_tab.width - ft_strlen(ft_itoa(nb)) - 1);
		ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
	}
}

void	ft_putnn2(long long nb, int nbl)
{
	if (g_tab.plus == 0 || (nb < 0 && g_tab.plus == 1))
	{
		if (g_tab.space == 0 && g_tab.zero == 0)
			ft_putnn21(nb, nbl);
		else if (g_tab.space == 1)
			ft_putnn22(nb, nbl);
		else if (g_tab.zero && g_tab.width)
		{
			if (g_tab.width <= nbl)
				ft_write(ft_itoa(nb), ft_strlen(ft_itoa(nb)));
			else
			{
				if (nb < 0)
					ft_putchar('-');
				ft_putnch('0', g_tab.width - ft_strlen(ft_itoa(nb)));
				ft_write(ft_itoa(FT_ABS(nb)), ft_strlen(ft_itoa(FT_ABS(nb))));
			}
		}
	}
	else if (g_tab.plus == 1)
		ft_putnn23(nb, nbl);
}
