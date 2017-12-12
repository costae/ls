/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file21.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:54 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putxx2(char *str)
{
	if (g_tab.prec <= ft_strlen(str))
		ft_putstr(str);
	else if (g_tab.prec > ft_strlen(str))
	{
		ft_putnch('0', (g_tab.prec - ft_strlen(str)));
		ft_putstr(str);
	}
}

void	ft_putxx3(char *str)
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

void	ft_putxx41(char *str)
{
	if (str[0] == '0')
		ft_putstr(str);
	else if (g_tab.width <= ft_strlen(str))
	{
		ft_putstr("0X");
		ft_putstr(str);
	}
	else
	{
		if (g_tab.minus)
		{
			ft_putstr("0X");
			ft_putstr(str);
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 2);
		}
		else if (g_tab.minus == 0)
		{
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 2);
			ft_putstr("0X");
			ft_putstr(str);
		}
	}
}

void	ft_putxx42(char *str)
{
	if (str[0] == '0')
		ft_putstr(str);
	else if (g_tab.width <= ft_strlen(str))
	{
		ft_putstr("0X");
		ft_putstr(str);
	}
	else
	{
		if (g_tab.minus)
		{
			ft_putstr("0X");
			ft_putstr(str);
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 2);
		}
		else if (g_tab.minus == 0)
		{
			ft_putstr("0X");
			ft_putnch('0', g_tab.width - ft_strlen(str) - 2);
			ft_putstr(str);
		}
	}
}

void	ft_putxx4(char *str)
{
	if (g_tab.zero == 0)
		ft_putxx41(str);
	else
		ft_putxx42(str);
}
