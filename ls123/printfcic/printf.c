/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:49 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		do_things1(va_list ap)
{
	if (g_tab.spec == 'i' || g_tab.spec == 'd')
		ft_putnbr1(ap);
	else if (g_tab.spec == 'D')
		ft_putnbr4(ap);
	else if (g_tab.spec == 'x')
		ft_putnbr8(ap);
	else if (g_tab.spec == 'X')
		ft_putnbr9(ap);
	else if (g_tab.spec == 'o')
		ft_putnbr6(ap);
	else if (g_tab.spec == 'O')
		ft_putnbr7(ap);
	else if (g_tab.spec == 'u')
		ft_putnbr4(ap);
	else if (g_tab.spec == 'U')
		ft_putnbr5(ap);
	else if (g_tab.spec == 'p')
	{
		g_ps = va_arg(ap, char *);
		ft_putaddr(g_ps);
	}
	else
		return ;
}

void		do_things2(va_list ap)
{
	if (g_tab.spec == 's')
	{
		g_s = va_arg(ap, char *);
		ft_putstr1(g_s);
	}
	else if (g_tab.spec == 'S')
	{
		g_ws = va_arg(ap, wchar_t *);
		ft_putwstr1(g_ws);
	}
	else if (g_tab.spec == 'c')
	{
		g_c = va_arg(ap, int);
		ft_putcharprec(g_c);
	}
	else if (g_tab.spec == 'C')
	{
		g_wc = va_arg(ap, wchar_t);
		ft_putchar(g_wc);
	}
	else if (g_tab.spec == '%')
	{
		ft_putproc();
	}
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;

	g_n = -1;
	g_print = 0;
	ft_refresh();
	va_start(ap, fmt);
	while (fmt[++g_n])
	{
		if (fmt[g_n] == '%')
		{
			ft_reg(fmt);
			if (g_tab.spec == 0)
				ft_putchar('%');
			else
			{
				do_things1(ap);
				do_things2(ap);
				ft_refresh();
			}
		}
		else
			ft_putchar(fmt[g_n]);
	}
	va_end(ap);
	return (g_print);
}
