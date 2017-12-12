/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:00 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_refresh(void)
{
	g_tab.punct = 0;
	g_tab.minus = 0;
	g_tab.plus = 0;
	g_tab.space = 0;
	g_tab.htag = 0;
	g_tab.zero = 0;
	g_tab.width = 0;
	g_tab.prec = 0;
	g_tab.spec = 0;
	g_tab.length = 0;
}

int		ft_islen(char c)
{
	if (c == 'h')
		return (2);
	else if (c == 'l')
		return (1);
	else if (c == 'j')
		return (3);
	else if (c == 'z')
		return (4);
	return (0);
}

int		ft_search(const char *fmt, int i)
{
	i++;
	while (fmt[i])
	{
		if (fmt[i] == 's' || fmt[i] == 'S' || fmt[i] == 'c' || fmt[i] == 'C' ||
				fmt[i] == 'd' || fmt[i] == 'D' || fmt[i] == 'i' ||
				fmt[i] == '%' || fmt[i] == 'o' || fmt[i] == 'O' ||
				fmt[i] == 'u' || fmt[i] == 'U' || fmt[i] == 'x' ||
				fmt[i] == 'X' || fmt[i] == 'p')
			return (i);
		else
			i++;
	}
	return (0);
}

void	ft_reg111(const char *fmt)
{
	if (fmt[g_n] == '.')
		g_tab.punct = 1;
	if (fmt[g_n] == '-')
		g_tab.minus = 1;
	if (fmt[g_n] == '+')
		g_tab.plus = 1;
	if (fmt[g_n] == ' ')
		g_tab.space = 1;
	if (fmt[g_n] == '#')
		g_tab.htag = 1;
	if (fmt[g_n] == '0')
		g_tab.zero = 1;
}

void	ft_reg(const char *fmt)
{
	int	i;

	i = ft_search(fmt, g_n);
	while (g_n <= i)
	{
		if (ft_isdigit1(fmt[g_n]) && g_tab.punct == 0)
			g_tab.width = ft_natoi(fmt);
		ft_reg111(fmt);
		if ((fmt[g_n - 1] != 'h' || fmt[g_n - 1] != 'l') && (fmt[g_n] == 'h' ||
					fmt[g_n] == 'l' || fmt[g_n] == 'j' || fmt[g_n] == 'j' ||
					fmt[g_n] == 'z'))
			g_tab.length = ft_islen(fmt[g_n]);
		if (fmt[g_n] == 'h' && fmt[g_n - 1] == 'h')
			g_tab.length = 22;
		if (fmt[g_n] == 'l' && fmt[g_n - 1] == 'l')
			g_tab.length = 11;
		if (ft_isdigit1(fmt[g_n]) && g_tab.punct == 1)
			g_tab.prec = ft_natoi(fmt);
		if (g_n - i == 0)
		{
			g_tab.spec = fmt[i];
			break ;
		}
		g_n++;
	}
}
