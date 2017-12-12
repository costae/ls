/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:58:15 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 16:58:17 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_print_as_list_part2(t_list *h_h, int s_max, int d_max, char *s)
{
	PALP;
	ft_print_insize(ft_itoa(h_h->data.size), s_max + 2);
	ft_print_time(h_h->data.time, d_max);
	if (g_file)
		ft_printf("%s\n", h_h->data.name);
	else if (h_h->data.rights[0] == 'l')
	{
		b = ft_readlink_file(h_h, s);
		if (g_flags[9])
		{
			ft_print_color(b, 'l');
			ft_printf("\n");
		}
		else
			ft_printf("%s\n", b);
	}
	else
		if (g_flags[9])
		{
			ft_print_color(s, h_h->data.rights[0]);
			ft_printf("\n");
		}
		else
			ft_printf("%s\n", s);
}

void	ft_print_as_list1_part1(t_list *h_h, int l_max, int u_max, int gr_max)
{
	ft_printf("%-12s", h_h->data.rights);
	ft_print_insize(ft_itoa(h_h->data.nlinks), l_max);
	if (g_flags[8] == 0)
		ft_print_insize2(h_h->data.owner, u_max + 1);
	if (g_flags[5] == 0)
		ft_print_insize2(h_h->data.group, gr_max);

}

void    ft_print_as_list(t_list *h_h)
{
	PAL1; PAL12; PAL13; PAL14;
	while (h_h)
	{
		s = ft_format_path(h_h->data.name);
		if (ft_check_a(s))
		{
			ft_print_as_list1_part1(h_h, l_max, u_max, gr_max);
			ft_print_as_list_part2(h_h, s_max, d_max, s);
						
		}
		h_h = h_h->next;
	}
}

void    ft_print_error(int er, const char *str)
{
	if (er == ENOTDIR)
		return ;
	if (g_first)
		ft_printf("\n%s\n", str);
	if (g_fnew && g_fnew->next)
		ft_printf("%s\n", str);
	if (er == EACCES)
		ft_printf("ls: %s: Permission denied\n", ft_format_path(str));
	if (er == ENOENT)
		ft_printf("ls: %s: No such file or directory\n", ft_format_path(str));
}
