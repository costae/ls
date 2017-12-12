/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:57:56 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 16:57:58 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    ft_show_files(char **av)
{
	int i;
	t_list *new;

	new = NULL;
	g_fnew = NULL;
	i = -1;
	while (av[++i])
		if (!opendir(av[i]))
		{
			if (errno == ENOTDIR)
				ft_push_to_list(av[i], &new, 0);
			else if (ft_file_exist(av[i]))
				ft_push_to_list(av[i], &g_fnew, -1);
		}
		else
			ft_push_to_list(av[i], &g_fnew, -1);
	if (new == NULL)
		return ;
	ft_sort_mode(&new);
	ft_sort_mode(&g_fnew);
	ft_print_files(new);
}

int     main(int ac, char **av)
{
	int n;

	g_fnew = NULL;
	g_fflag = 0;
	g_notfound = 0;
	g_first = 0;
	g_rec = 0;
	g_file = 0;
	if (ac > 1)
	{
		n = ft_check_flags(av);
		ft_check_exist(av + n);
		ft_show_files(av + n);
	}
	if (g_fnew == NULL && (g_fflag || g_notfound))
		return (0);
	else if ((g_fnew == NULL && !g_fflag) || ac == 1)
		ft_push_to_list(".", &g_fnew, -1);
	if (g_fnew->next != NULL)
		g_fflag = 1;
	g_file = 0;
	ft_show_folders();
}
