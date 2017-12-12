/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:23:54 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:23:56 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char    *ft_find_path(const char *str, const char *source)
{
	char *yes;

	yes = ft_strdup(str);
	yes = ft_strjoin(yes, "/");
	yes = ft_strjoin(yes, source);
	return (yes);

}

char    *ft_format_path(const char *path)
{
	char **found;
	char *temp;
	int i;

	i = -1;
	found = ft_strsplit(path, '/');
	while (found[++i])
		;
	temp = found[i - 1];
	g_first = 1;
	return (temp);
}

int     ft_check_a(char *s)
{
	if (s && s[0] == '.')
	{
		if (g_flags[1] == 0)
			return (0);
		if (g_flags[1] != 0)
			return (1);
	}
	return (1);
}

void    ft_show_blocks(t_list *here)
{
	int count;
	char *s;

	count = 0;
	while (here)
	{
		s = ft_format_path(here->data.name);
		if (ft_check_a(s))
			count += here->data.block;
		here = here->next;
	}
	ft_printf("total %d\n", count);
}

int ft_find_lmax(t_list *h_h)
{
	t_list *here;
	int lmax;

	lmax = 0;
	here = h_h;
	while (here)
	{
		if (ft_check_a(ft_format_path(here->data.name)))
			if (here->data.nlinks > lmax)
				lmax = here->data.nlinks;
		here = here->next;
	}
	return (strlen(ft_itoa(lmax)));
}
