/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:47 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putnb(signed long long int nb)
{
	int		nbl;

	nbl = ft_nblen(nb);
	if (g_tab.prec == 0 && g_tab.punct == 1)
		ft_putnn1(nb);
	else if (g_tab.width && g_tab.prec < g_tab.width && g_tab.prec <= nbl
			&& g_tab.minus == 0)
		ft_putnn2(nb, nbl);
	else if (g_tab.width && g_tab.prec < g_tab.width && g_tab.prec > nbl
			&& g_tab.minus == 0)
		ft_putnn3(nb, nbl);
	else if (g_tab.prec && g_tab.width <= g_tab.prec)
		ft_putnn4(nb, nbl);
	else if (g_tab.width && g_tab.prec < g_tab.width && g_tab.prec > nbl
			&& g_tab.minus == 1)
		ft_putnn5(nb, nbl);
	else if (g_tab.width >= g_tab.prec && g_tab.prec < nbl
			&& g_tab.width > nbl && g_tab.minus == 0)
		ft_putnn6(nb, nbl);
	else if (g_tab.width >= g_tab.prec && g_tab.prec < nbl
			&& g_tab.width > nbl && g_tab.minus == 1)
		ft_putnn7(nb, nbl);
	else
		ft_putnn8(nb, nbl);
}
