/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file22.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:56 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puto1(char *str)
{
	if (g_tab.htag == 0)
		ft_putnch(' ', g_tab.width);
	else if (g_tab.htag == 1)
	{
		if (g_tab.minus == 0)
		{
			ft_putstr(str);
			ft_putnch(' ', g_tab.width - ft_strlen(str));
		}
		else
		{
			ft_putnch(' ', g_tab.width - ft_strlen(str));
			ft_putstr(str);
		}
	}
}

void	ft_puto21(char *str)
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

void	ft_puto22(char *str)
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

void	ft_puto23(char *str)
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

void	ft_puto24(char *str)
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
