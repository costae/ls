/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:38 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int					ft_isdigit1(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}

int					ft_wstrlen(wchar_t *s)
{
	const wchar_t	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

void				ft_putwstr1(wchar_t *str)
{
	if (g_tab.width && g_tab.minus == 0)
	{
		if (g_tab.width <= ft_wstrlen(str))
			ft_putwstr2(str);
		else
		{
			ft_putnch(' ', g_tab.width - ft_wstrlen(str));
			ft_putwstr2(str);
		}
	}
	else if (g_tab.prec)
	{
		if (g_tab.prec < ft_wstrlen(str))
			ft_putnwstr2(str, g_tab.prec);
		else
			ft_putwstr2(str);
	}
	else if (g_tab.minus)
	{
		ft_putwstr2(str);
		ft_putnch(' ', g_tab.width - ft_wstrlen(str));
	}
}

void				ft_putcharprec(char c)
{
	if (ft_isascii(c) == 0)
		ft_putcharsimple(c);
	else if (g_tab.width && g_tab.prec == 0 && g_tab.minus == 0 && c != 0)
	{
		ft_putnch(' ', g_tab.width - 1);
		ft_putchar(c);
	}
	else if (g_tab.width && g_tab.prec == 0 && g_tab.minus)
	{
		ft_putchar(c);
		ft_putnch(' ', g_tab.width - 1);
	}
	else if (c == 0 && g_tab.prec)
		ft_putchar(0);
	else if (g_tab.width && c == 0)
	{
		ft_putchar(0);
		ft_putchar(' ');
	}
	else if (g_tab.prec == 0 && g_tab.width == 0 && g_tab.minus == 0)
		ft_putchar(c);
	else
		ft_putchar(c);
}
