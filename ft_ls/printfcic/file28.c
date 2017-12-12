/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file28.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:28 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putss1(char *str, int i)
{
	if (g_tab.width > (i - g_tab.prec) && (i - g_tab.prec > 0))
	{
		ft_putnch(' ', g_tab.width - g_tab.prec);
		ft_putnstr(str, g_tab.prec);
	}
	if (g_tab.width < (i - g_tab.prec))
		ft_putnstr(str, g_tab.prec);
	if (g_tab.width > i && g_tab.prec > i)
	{
		ft_putnch(' ', g_tab.width - i);
		ft_putstr(str);
	}
	if (g_tab.prec > i && g_tab.width < i)
		ft_putstr(str);
}

void		ft_putss2(char *str, int i)
{
	if (g_tab.width > (i - g_tab.prec) && (i - g_tab.prec > 0))
	{
		ft_putnstr(str, g_tab.prec);
		ft_putnch(' ', g_tab.width - g_tab.prec);
	}
	if (g_tab.width < (i - g_tab.prec))
		ft_putnstr(str, g_tab.prec);
	if (g_tab.prec > i)
		ft_putstr(str);
}

void		ft_putss3(char *str, int i)
{
	if (g_tab.width <= i)
		ft_putstr(str);
	else
	{
		ft_putnch(' ', g_tab.width - i);
		ft_putstr(str);
	}
}

void		ft_putss4(char *str, int i)
{
	if (g_tab.prec < i)
		ft_putnstr(str, g_tab.prec);
	else
		ft_putstr(str);
}

void		ft_putss5(char *str, int i)
{
	(void)i;
	if (ft_strcmp(str, "") == 0)
		ft_putnch(' ', g_tab.width);
	else
		ft_putnstr(str, g_tab.prec);
}
