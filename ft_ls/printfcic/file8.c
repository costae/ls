/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:45 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putss6(char *str, int i)
{
	ft_putstr(str);
	ft_putnch(' ', g_tab.width - i);
}

void		ft_putss7(char *str, int i)
{
	ft_putstr(str);
	ft_putnch(' ', g_tab.width - i);
}

void		ft_putstr123(char *str, int i)
{
	if (g_tab.minus)
		ft_putss7(str, i);
	else
		ft_putstr(str);
}

int			ft_natoi(const char *str)
{
	int		nb;

	nb = 0;
	while (ft_isdigit(str[g_n]))
	{
		nb = nb * 10 + str[g_n] - '0';
		g_n++;
	}
	return (nb);
}

void		ft_putstr1(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (str == NULL)
		ft_putstr("(null)");
	else if (g_tab.prec == 0 && g_tab.width && g_tab.punct)
		ft_putnch(' ', g_tab.width);
	else if (g_tab.prec && g_tab.width && g_tab.minus == 0 &&
			ft_strcmp(str, "") > 0)
		ft_putss1(str, i);
	else if (g_tab.prec && g_tab.width && g_tab.minus == 1 &&
			(ft_strcmp(str, "")) > 0)
		ft_putss2(str, i);
	else if (g_tab.width && g_tab.minus == 0 && g_tab.prec == 0)
		ft_putss3(str, i);
	else if (g_tab.prec && g_tab.width == 0 && g_tab.minus == 0)
		ft_putss4(str, i);
	else if (g_tab.prec && g_tab.minus)
		ft_putss5(str, i);
	else if (g_tab.width && g_tab.minus && str)
		ft_putss6(str, i);
	else if ((ft_strcmp(str, "") == 0 && g_tab.width) || g_tab.minus)
		ft_putnch(' ', g_tab.width);
	else
		ft_putstr123(str, i);
}
