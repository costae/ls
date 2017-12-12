/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file29.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:31 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putx11(char *str)
{
	if (g_tab.width <= ft_strlen(str))
	{
		ft_putnch('0', g_tab.prec - ft_strlen(str));
		ft_putstr(str);
	}
	else
	{
		ft_putnch(' ', g_tab.width - g_tab.prec);
		ft_putnch('0', g_tab.prec - ft_strlen(str));
		ft_putstr(str);
	}
}

void	ft_putx12(char *str)
{
	if (g_tab.width <= ft_strlen(str))
	{
		ft_write(str, g_tab.prec);
	}
	else
	{
		ft_putnch(' ', g_tab.width - ft_strlen(str));
		ft_write(str, ft_strlen(str));
	}
}

void	ft_putx13(char *str)
{
	if (g_tab.prec >= ft_strlen(str))
	{
		if (g_tab.width <= ft_strlen(str))
		{
			ft_putstr(str);
		}
		else
		{
			ft_putnch('0', g_tab.width - ft_strlen(str));
			ft_putstr(str);
		}
	}
	else
	{
		if (g_tab.width <= ft_strlen(str))
		{
			ft_write(str, g_tab.prec);
		}
		else
		{
			ft_putnch('0', g_tab.width - ft_strlen(str));
			ft_write(str, ft_strlen(str));
		}
	}
}

void	ft_putx1(char *str)
{
	if (g_tab.zero == 0)
	{
		if (g_tab.prec >= ft_strlen(str))
			ft_putx11(str);
		else if (g_tab.prec < ft_strlen(str) && g_tab.prec > 0)
			ft_putx12(str);
		else
		{
			if (g_tab.width <= ft_strlen(str))
			{
				ft_write(str, ft_strlen(str));
			}
			else
			{
				ft_putnch(' ', g_tab.width - ft_strlen(str));
				ft_write(str, ft_strlen(str));
			}
		}
	}
	else if (g_tab.zero == 1)
		ft_putx13(str);
}

void	ft_putx2(char *str)
{
	if (g_tab.prec <= ft_strlen(str))
		ft_putstr(str);
	else if (g_tab.prec > ft_strlen(str))
	{
		ft_putnch('0', (g_tab.prec - ft_strlen(str)));
		ft_putstr(str);
	}
}
