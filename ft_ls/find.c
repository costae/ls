/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:20:29 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:20:59 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_check_ispoint(char *s)
{
	if (s[0] != '.')
		return (0);
	if (s[1] == '\0')
		return (1);
	if (s[1] == '.' && !s[2])
		return (1);
	return (0);
}

size_t	ft_find_nmax(t_list *h_h)
{
	t_list *here;
	size_t u_max;

	u_max = 0;
	here = h_h;
	while (here)
	{
		if (ft_check_a(ft_format_path(here->data.name)))
			if (strlen(ft_format_path(here->data.name)) > u_max)
				u_max = strlen(ft_format_path(here->data.name));
		here = here->next;
	}
	return (u_max);
}

int		ft_get_winsize(t_list *h_h)
{
	struct winsize w;
	int n;

	n = ft_find_nmax(h_h);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int		ft_count_inlist(t_list *h_h)
{
	int count;

	count = 0;
	while (h_h)
	{
		if (ft_check_a(ft_format_path(h_h->data.name)))
			count++;
		h_h = h_h->next;
	}
	return (count);
}
