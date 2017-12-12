/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:59:03 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 16:59:05 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int ft_show_inside(const char *str)
{
	struct dirent *dirp;
	t_list *h_h;
	DIR *dir;
	DIR *dir2;
	int my_flag = 0;

	h_h = NULL;
	dir = opendir(str);
	if (!dir)
	{
		ft_print_error(errno, str);
		return (0);
	}
	while ((dirp = readdir(dir)) != NULL)
	{
		if (!(dir2 = opendir(ft_find_path(str, dirp->d_name))) && errno == EACCES)
		{
			if (ft_check_ispoint(dirp->d_name))
				my_flag = 1;
			if (my_flag)
			{
				if (ft_check_a(dirp->d_name))
					ft_printf("ls: %s: Permission denied\n", dirp->d_name);
				continue;
			}
		}
		if (dir2)
			closedir(dir2);
		if (my_flag)
			return (0);
		if (!(dir2 = opendir(ft_find_path(str, dirp->d_name))) && errno == ENOENT)
		{
			if (ft_check_a(dirp->d_name))
				ft_printf("ls: %s: No such file or directory\n", dirp->d_name);
			continue;
		}
		if (dir2)
			closedir(dir2);
		if (ft_check_a(dirp->d_name))
			ft_push_to_list(ft_find_path(str, dirp->d_name), &h_h, 0);
	}
	if (g_first)
		ft_printf("\n");
	if (g_fflag)
		ft_printf("%s:\n", str);
	ft_sort_mode(&h_h);
	if (g_flags[0] == 1 || g_flags[5] == 1 || g_flags[8] == 1)
	{
		if (ft_check_c_b(h_h))
			ft_print_as_list2(h_h);
		else
			ft_print_as_list(h_h);
		closedir(dir);
		return (1);
	}
	else
		ft_print_inwin(h_h);
	closedir(dir);
	return (1);
}
