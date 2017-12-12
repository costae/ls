/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:24:01 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:24:03 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int ft_find_umax(t_list *h_h)
{
	t_list *here;
	size_t u_max;

	u_max = 0;
	here = h_h;
	while (here)
	{
		if (ft_check_a(ft_format_path(here->data.name)))
			if (strlen(here->data.owner) > u_max)
				u_max = strlen(here->data.owner);
		here = here->next;
	}
	return (u_max);
}

int ft_find_gmax(t_list *h_h)
{
	t_list *here;
	size_t u_max;

	u_max = 0;
	here = h_h;
	while (here)
	{
		if (ft_check_a(ft_format_path(here->data.name)))
			if (strlen(here->data.group) > u_max)
				u_max = strlen(here->data.group);
		here = here->next;
	}
	return (u_max);
}

int ft_find_smax(t_list *h_h)
{
	t_list *here;
	int lmax;

	lmax = 0;
	here = h_h;
	while (here)
	{
		if (ft_check_a(ft_format_path(here->data.name)))
			if (here->data.size > lmax)
				lmax = here->data.size;
		here = here->next;
	}
	return (strlen(ft_itoa(lmax)));
}

int ft_date_max(t_list *h_h)
{
	t_list *here;
	size_t lmax;
	char *str;
	char **found;

	lmax = 0;
	here = h_h;
	while (here)
	{
		str = here->data.fortime;
		found = ft_strsplit(str, ' ');
		if (ft_check_a(ft_format_path(here->data.name)))
			if (strlen(found[2]) > lmax)
				lmax = strlen(found[2]);
		here = here->next;
	}
	return (lmax);
}

void    ft_print_insize(char *str, int n)
{
	int i;
	int spaces;

	i = -1;
	spaces = n - strlen(str);
	while (++i < spaces)
		ft_printf(" ");
	i = -1;
	ft_printf("%s", str);
}
