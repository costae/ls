/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:58:21 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 16:58:23 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_print_as_list2_part3(t_list *h_h, char *s)
{
	char *b = NULL;

	s = ft_format_path(h_h->data.name);
	b = ft_readlink_file(h_h, s);
	if (g_flags[9])
	{
		ft_print_color(b, 'l');
		ft_printf("\n");
	}
	else
		ft_printf("%s\n", b);
}

void ft_print_as_list2_part4(t_list *h_h, char *s)
{

	if (g_flags[9])
	{
		ft_print_color(s, h_h->data.rights[0]);
		ft_printf("\n");
	}
	else
		ft_printf("%s\n", s);
}

void	ft_print_as_list2_part1(t_list *h_h, int l_max, int u_max, int gr_max)
{
	ft_printf("%-12s", h_h->data.rights);
	ft_print_insize(ft_itoa(h_h->data.nlinks), l_max);
	if (g_flags[8] == 0)
		ft_print_insize2(h_h->data.owner, u_max + 1);
	if (g_flags[5] == 0)
		ft_print_insize2(h_h->data.group, gr_max);
}

void	ft_print_as_list2_part2(t_list *h_h, int maj_max, int min_max, int d_max)
{
	char *s;

	s = ft_format_path(h_h->data.name);
	if (h_h->data.rights[0] == 'c' || h_h->data.rights[0] == 'b')
	{
		ft_print_insize(ft_itoa(h_h->data.maj), maj_max + 3);
		ft_printf(",");
		ft_print_insize(ft_itoa(h_h->data.min), min_max + 1);
	}
	else
		ft_print_insize(ft_itoa(h_h->data.size), min_max + maj_max + 5);
	ft_print_time(h_h->data.time, d_max);
	if (g_file)
		ft_printf("%s\n", h_h->data.name);
	else if (h_h->data.rights[0] == 'l')
		ft_print_as_list2_part3(h_h, s);
	else
		ft_print_as_list2_part4(h_h, s);
}

void    ft_print_as_list2(t_list *h_h)
{
	int l_max;
	int u_max;
	int gr_max;
	int maj_max;
	int min_max;
	int d_max;
	char *s;

	ft_show_blocks(h_h);
	l_max = ft_find_lmax(h_h);
	u_max = ft_find_umax(h_h);
	gr_max = ft_find_gmax(h_h);
	maj_max = ft_find_majmax(h_h);
	min_max = ft_find_minmax(h_h);
	d_max = ft_date_max(h_h);
	while (h_h)
	{
		s = ft_format_path(h_h->data.name);
		if (ft_check_a(s))
		{
			ft_print_as_list2_part1(h_h, l_max, u_max, gr_max);
			ft_print_as_list2_part2(h_h, maj_max, min_max, d_max);
		}
		h_h = h_h->next;
	}
}
