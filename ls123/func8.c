/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:24:12 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:24:15 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    ft_print_insize2(char *str, int n)
{
	int i;
	int spaces;

	i = -1;
	spaces = n - strlen(str);
	ft_printf(" %s", str);
	while (++i < spaces)
		ft_printf(" ");
}

void    ft_print_color(const char *s, char t)
{
	if (t == 'd')
		ft_printf(GREEN "%s" RESET, s);
	else if (t == 'l')
		ft_printf(CYAN "%s" RESET, s);
	else if (t == '-')
		ft_printf(GRAY "%s" RESET, s);
	else if (t == 'c' || t == 'b')
		ft_printf(BG_RED "%s" RESET BG_DEFAULT , s);
	else
		ft_printf("%s", s);
}

void    ft_print_forsize(char *str, int n, char t)
{
	int i;
	int spaces;

	i = -1;
	spaces = n - strlen(str);
	if (g_flags[9])
		ft_print_color(str, t);
	else
		ft_printf("%s", str);
	while (++i <= spaces)
		ft_printf(" ");
}

void    ft_print_time(time_t our_time, int date_max)
{
	char *str_time;
	char **found;
	char **t_form;
	int n;
	time_t now;

	time(&now);
	str_time = ctime(&our_time);
	found = ft_strsplit(str_time, ' ');
	ft_printf(" %s", found[1]);
	n = date_max - strlen(found[2]);
	ft_printf(" ");
	ft_printf("%2s", found[2]);
	ft_printf(" ");
	t_form = ft_strsplit(found[3], ':');
	if ((long)(now - our_time) > 15768000)
	{
		ft_printf("%5s ", found[4]);
		return ;
	}
	ft_printf("%s", t_form[0]);
	ft_printf(":");
	ft_printf("%s ", t_form[1]);
}

int     ft_find_majmax(t_list *h_h)
{
	t_list *here;
	int lmax;

	lmax = 0;
	here = h_h;
	while (here)
	{
		if (here->data.maj > lmax)
			lmax = here->data.maj;
		here = here->next;
	}
	return (strlen(ft_itoa(lmax)));
}
