/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:34 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puto5(char *str)
{
	if (g_tab.zero == 0)
		ft_puto51(str);
	else
		ft_puto52(str);
}

void	ft_putstr4(char *str)
{
	if (g_tab.prec == 0 && g_tab.punct == 1)
		ft_puto1(str);
	else if (g_tab.width && g_tab.minus == 0 && g_tab.htag == 0)
		ft_puto2(str);
	else if (g_tab.prec && g_tab.width <= g_tab.prec && g_tab.htag == 0)
		ft_puto3(str);
	else if (g_tab.minus && g_tab.htag == 0)
		ft_puto4(str);
	else if (g_tab.htag)
		ft_puto5(str);
	else
		ft_putstr(str);
}

void	ft_putnstr(char *str, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar(str[i]);
}

void	ft_write(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
}
