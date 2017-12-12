/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:15 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putvv8(unsigned long long nb, int nbl)
{
	(void)nbl;
	if (g_tab.plus == 0)
	{
		if (g_tab.space == 1 && (g_tab.spec == 'd' || g_tab.spec == 'D' ||
					g_tab.spec == 'i'))
		{
			ft_putchar(' ');
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		}
		else
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
	else if (g_tab.plus == 1)
	{
		if (nb < 4000000)
		{
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
		}
		else
			ft_write(ft_utoa(nb), ft_strlen(ft_utoa(nb)));
	}
}

void	ft_sasati(unsigned long long int nb)
{
	int nbl;

	nbl = ft_nblen(nb);
	if (g_tab.prec == 0 && g_tab.punct == 1)
		ft_putvv1(nb);
	else if (g_tab.width && g_tab.prec < g_tab.width && g_tab.prec <= nbl
			&& g_tab.minus == 0)
		ft_putvv2(nb, nbl);
	else if (g_tab.width && g_tab.prec < g_tab.width && g_tab.prec > nbl
			&& g_tab.minus == 0)
		ft_putvv3(nb, nbl);
	else if (g_tab.prec && g_tab.width <= g_tab.prec)
		ft_putvv4(nb, nbl);
	else if (g_tab.width && g_tab.prec < g_tab.width && g_tab.prec > nbl
			&& g_tab.minus == 1)
		ft_putvv5(nb, nbl);
	else if (g_tab.width >= g_tab.prec && g_tab.prec < nbl && g_tab.width > nbl
			&& g_tab.minus == 0)
		ft_putvv6(nb, nbl);
	else if (g_tab.width >= g_tab.prec && g_tab.prec < nbl && g_tab.width > nbl
			&& g_tab.minus == 1)
		ft_putvv7(nb, nbl);
	else
		ft_putvv8(nb, nbl);
}

void	ft_putnbr2(va_list ap)
{
	if (g_tab.length == 11)
	{
		g_i = va_arg(ap, long long int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 22)
	{
		g_i = (signed char)va_arg(ap, int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 4)
	{
		g_i = va_arg(ap, size_t);
		ft_putnb(g_i);
	}
}
