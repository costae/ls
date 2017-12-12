/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:58:49 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 16:58:52 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    show_recursively(t_list **head)
{
	t_list  *folders;
	t_list *sorted =  NULL;
	DIR *dir;
	DIR *dir2;
	int my_flag = 0;
	struct dirent *dirp;
	g_fhead = *head;
	folders = NULL;
	while ((*head))
	{
		folders = NULL;
		sorted = NULL;
		if ( (*head) && !(*head)->ord && ft_check_ispoint(ft_format_path((*head)->data.name)))
		{
			(*head) = (*head)->next;
			continue;
		}
		g_fflag = 1;
		if ((*head)->data.rights[0] == 'd')
		{
			dir = opendir((*head)->data.name);
			if (!dir)
			{
				(*head) = (*head)->next;
				continue ;
			}
		}
		else if ((*head)->data.rights[0] != 'd')
		// if (!(dir))
		{
			(*head) = (*head)->next;
			continue ;
		}
		my_flag = 0;
		if (g_first)
			ft_printf("\n");
		if (g_fflag)
			ft_printf("%s:\n", (*head)->data.name);
		while ((dirp = readdir(dir)) != NULL)
		{
			if (!(dir2 = opendir(ft_find_path((*head)->data.name, dirp->d_name))) && errno == EACCES)
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
			if (!(dir2 = opendir(ft_find_path((*head)->data.name, dirp->d_name))) && errno == ENOENT)
			{
				if (ft_check_a(dirp->d_name))
					ft_printf("ls: %s: No such file or directory\n", dirp->d_name);
				continue;
			}
			if (dir2)
				closedir(dir2);
			if (my_flag)
				break ;
			if (ft_check_a(dirp->d_name))
				ft_push_to_list(ft_find_path((*head)->data.name, dirp->d_name), &folders, 0);
		}
		if (dir)
			closedir(dir);
		ft_sort_mode(&folders);
		sorted = folders;
		if (g_flags[0] == 1 || g_flags[5] == 1 || g_flags[8] == 1)
		{
			if (ft_check_c_b(folders))
				ft_print_as_list2(sorted);
			else
				ft_print_as_list(folders);
		}
		else
			ft_print_inwin(sorted);
		if (folders != NULL)
			show_recursively(&folders);
		ft_free_the_list(&g_fhead);
		*head = (*head)->next;
	}
}
