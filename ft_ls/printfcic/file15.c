/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:38 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr8(va_list ap)
{
	if (g_tab.length == 22)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 2)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 1)
		g_i = va_arg(ap, unsigned long int);
	else if (g_tab.length == 11)
		g_i = va_arg(ap, unsigned long long int);
	else if (g_tab.length == 3)
		g_i = va_arg(ap, uintmax_t);
	else if (g_tab.length == 4)
		g_i = va_arg(ap, size_t);
	else
		g_i = va_arg(ap, unsigned int);
	ft_putstr2(ft_itoa_base(g_i, 16));
}

void	ft_putnbr9(va_list ap)
{
	if (g_tab.length == 22)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 2)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 1)
		g_i = va_arg(ap, unsigned long int);
	else if (g_tab.length == 11)
		g_i = va_arg(ap, unsigned long);
	else if (g_tab.length == 3)
		g_i = va_arg(ap, uintmax_t);
	else if (g_tab.length == 1)
		g_i = va_arg(ap, size_t);
	else
		g_i = va_arg(ap, unsigned int);
	ft_putstr3(ft_utoa_base2(g_i, 16));
}

void	ft_putnbr6(va_list ap)
{
	if (g_tab.length == 22)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 2)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 1)
		g_i = va_arg(ap, unsigned long int);
	else if (g_tab.length == 11)
		g_i = va_arg(ap, unsigned long long int);
	else if (g_tab.length == 3)
		g_i = va_arg(ap, uintmax_t);
	else if (g_tab.length == 1)
		g_i = va_arg(ap, size_t);
	else
		g_i = va_arg(ap, unsigned int);
	ft_putstr4(ft_utoa_base2(g_i, 8));
}

void	ft_putnbr7(va_list ap)
{
	if (g_tab.length == 22)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 2)
		g_i = (unsigned char)va_arg(ap, int);
	else if (g_tab.length == 1)
		g_i = va_arg(ap, unsigned long int);
	else if (g_tab.length == 11)
		g_i = va_arg(ap, unsigned long long int);
	else if (g_tab.length == 3)
		g_i = va_arg(ap, uintmax_t);
	else if (g_tab.length == 1)
		g_i = va_arg(ap, size_t);
	else
		g_i = va_arg(ap, unsigned long);
	ft_putstr4(ft_utoa_base2(g_i, 8));
}

void	ft_putproc(void)
{
	if (g_tab.width)
	{
		if (g_tab.minus == 0)
		{
			ft_putnch(' ', g_tab.width - 1);
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			ft_putnch(' ', g_tab.width - 1);
		}
	}
	else
		ft_putchar('%');
}
