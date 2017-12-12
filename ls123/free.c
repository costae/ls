/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:21:09 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:21:34 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_file_exist (char *filename)
{
	struct stat   buffer;
	return (lstat (filename, &buffer) == 0);
}

void	ft_free_the_list(t_list **fhead)
{
	t_list *list;

	list = NULL;
	while (list != NULL)
	{
		list = (*fhead)->next;
		free((*fhead));
		(*fhead) = list;
	}
}

void    ft_show_folders()
{
	t_list *hey;

	hey = g_fnew;
	if (g_flags[3])
		show_recursively(&g_fnew);
	else
	{
		while (hey)
		{
			ft_show_inside(hey->data.name);
			hey = hey->next;
		}
	}
}

void    ft_check_exist(char **av)
{
	int i;

	i = -1;
	while (*(av + ++i))
	{
		if (!ft_file_exist(av[i]))
		{
			g_notfound =  1;
			ft_printf("ls: %s: No such file or directory\n", av[i]);
		}
	}
}

void    ft_print_files(t_list *list)
{
	while (list)
	{
		g_first = 1;
		g_fflag = 1;
		if (g_flags[0])
			break;
		if (ft_check_a(list->data.name))
		{
			ft_printf("%s\n", list->data.name);
		}
		list = list->next;
	}
	g_file = 1;
	if (g_flags[0])
		ft_print_as_list(list);
}
