/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:20 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putx3(char *str)
{
	if (g_tab.prec <= ft_strlen(str))
	{
		ft_putstr(str);
		ft_putnch(' ', g_tab.width - ft_strlen(str));
	}
	else if (g_tab.prec > ft_strlen(str))
	{
		ft_putnch('0', g_tab.prec - ft_strlen(str));
		ft_putstr(str);
		ft_putnch(' ', g_tab.width - g_tab.prec);
	}
}

void	ft_putx4(char *str)
{
	if (str[0] == '0')
		ft_putstr(str);
	else if (g_tab.width <= ft_strlen(str))
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
	else
	{
		if (g_tab.minus)
		{
			ft_putstr("0x");
			ft_putstr(str);
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 2);
		}
		else if (g_tab.minus == 0)
		{
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 2);
			ft_putstr("0x");
			ft_putstr(str);
		}
	}
}

void	ft_putx5(char *str)
{
	if (str[0] == '0')
		ft_putstr(str);
	else if (g_tab.width <= ft_strlen(str))
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
	else
	{
		if (g_tab.minus)
		{
			ft_putstr("0x");
			ft_putstr(str);
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 2);
		}
		else if (g_tab.minus == 0)
		{
			ft_putstr("0x");
			ft_putnch('0', g_tab.width - ft_strlen(str) - 2);
			ft_putstr(str);
		}
	}
}

void	ft_putstr2(char *str)
{
	if (g_tab.prec == 0 && g_tab.punct == 1)
		ft_putnch(' ', g_tab.width);
	else if (g_tab.width && g_tab.minus == 0 && g_tab.htag == 0)
		ft_putx1(str);
	else if (g_tab.prec && g_tab.width <= g_tab.prec && g_tab.htag == 0)
		ft_putx2(str);
	else if (g_tab.minus && g_tab.htag == 0)
		ft_putx3(str);
	else if (g_tab.htag)
	{
		if (g_tab.zero == 0)
			ft_putx4(str);
		else
			ft_putx5(str);
	}
	else
		ft_putstr(str);
}
