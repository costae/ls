/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:17 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr1(va_list ap)
{
	if (g_tab.length == 0)
	{
		g_i = va_arg(ap, int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 1)
	{
		g_i = va_arg(ap, long int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 2)
	{
		g_i = (short int)va_arg(ap, int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 3)
	{
		g_i = va_arg(ap, intmax_t);
		ft_putnb(g_i);
	}
	ft_putnbr2(ap);
}

void	ft_putnn(va_list ap)
{
	if (g_tab.length == 11)
	{
		g_i = va_arg(ap, long long int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 22)
	{
		g_i = (unsigned char)va_arg(ap, int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 4)
	{
		g_i = va_arg(ap, size_t);
		ft_putnb(g_i);
	}
}

void	ft_putnbr3(va_list ap)
{
	if (g_tab.length == 0)
	{
		g_i = va_arg(ap, unsigned int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 1)
	{
		g_i = va_arg(ap, unsigned long int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 2)
	{
		g_i = (unsigned short int)va_arg(ap, int);
		ft_putnb(g_i);
	}
	if (g_tab.length == 3 || g_tab.length == 4)
	{
		g_i = va_arg(ap, uintmax_t);
		ft_putnb(g_i);
	}
	ft_putnn(ap);
}

void	ft_putnbr4(va_list ap)
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
	ft_sasati(g_i);
}

void	ft_putnbr5(va_list ap)
{
	if (g_tab.length == 22)
		g_ui = (unsigned char)va_arg(ap, unsigned long int);
	else if (g_tab.length == 2)
		g_ui = va_arg(ap, unsigned long int);
	else if (g_tab.length == 1)
		g_ui = va_arg(ap, unsigned long long int);
	else if (g_tab.length == 11)
		g_ui = va_arg(ap, unsigned long long int);
	else if (g_tab.length == 3)
		g_ui = va_arg(ap, uintmax_t);
	else if (g_tab.length == 1)
		g_ui = va_arg(ap, size_t);
	else
		g_ui = va_arg(ap, uintmax_t);
	ft_sasati(g_ui);
}
