/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:58:28 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 16:58:29 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void ft_corect1(t_list *new, char **s, char *color, int j)
{
	while (new)
	{
		s[++j] = ft_strdup(ft_format_path(new->data.name));
		color[j] = new->data.rights[0];
		new = new->next;
	}
}

void ft_print_inwin(t_list *h_h)
{
	PINW; PINW2; PINW3; PINW4; PINW5; PINW6;
	if (!count)
		return ;
	NAS;
	while (++k < m)
		(count % m == 0) ? arr[k] = count / m : SAD DAS;
	i = 0;
	while (i < count)
	{
		j = red;
		k = 0;
		while (k != m)
		{
			if (j >= count)
				break;
			ft_print_forsize(s[j], n, color[j]);
			i++;
			j += arr[k];
			k++;
		}
		red++;
		if (red > count)
			break;
		ft_printf("\n");
	}
}
