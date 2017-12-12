/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file23.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:59 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puto2(char *str)
{
	if (g_tab.zero == 0)
	{
		if (g_tab.prec >= ft_strlen(str))
			ft_puto21(str);
		else if (g_tab.prec < ft_strlen(str) && g_tab.prec > 0)
			ft_puto22(str);
		else
			ft_puto23(str);
	}
	else if (g_tab.zero == 1)
		ft_puto24(str);
}

void	ft_puto3(char *str)
{
	if (g_tab.prec <= ft_strlen(str))
		ft_putstr(str);
	else if (g_tab.prec > ft_strlen(str))
	{
		ft_putnch('0', (g_tab.prec - ft_strlen(str)));
		ft_putstr(str);
	}
}

void	ft_puto4(char *str)
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

void	ft_puto51(char *str)
{
	if (str[0] == '0')
		ft_putstr(str);
	else if (g_tab.width <= ft_strlen(str))
	{
		ft_putstr("0");
		ft_putstr(str);
	}
	else
	{
		if (g_tab.minus)
		{
			ft_putstr("0");
			ft_putstr(str);
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 1);
		}
		else if (g_tab.minus == 0)
		{
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 1);
			ft_putstr("0");
			ft_putstr(str);
		}
	}
}

void	ft_puto52(char *str)
{
	if (str[0] == '0')
		ft_putstr(str);
	else if (g_tab.width <= ft_strlen(str))
	{
		ft_putstr("0");
		ft_putstr(str);
	}
	else
	{
		if (g_tab.minus)
		{
			ft_putstr("0");
			ft_putstr(str);
			ft_putnch(' ', g_tab.width - ft_strlen(str) - 1);
		}
		else if (g_tab.minus == 0)
		{
			ft_putstr("0");
			ft_putnch('0', g_tab.width - ft_strlen(str) - 1);
			ft_putstr(str);
		}
	}
}
