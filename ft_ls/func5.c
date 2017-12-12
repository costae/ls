/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:23:42 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:23:47 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    ft_merge_sort_by_name(t_list **list)
{
	t_list *head;
	t_list *one;
	t_list *two;

	head = *list;
	one = (t_list*)malloc(sizeof(t_list) * 2048);
	two = (t_list*)malloc(sizeof(t_list) * 2048);
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_list_split(head, &one, &two);
	ft_merge_sort_by_name(&one);
	ft_merge_sort_by_name(&two);
	*list = ft_sorted_merge_by_name(one, two);
}

void    ft_merge_sort_by_name_rev(t_list **list)
{
	t_list *head;
	t_list *one;
	t_list *two;

	head = *list;
	one = (t_list*)malloc(sizeof(t_list) * 2048);
	two = (t_list*)malloc(sizeof(t_list) * 2048);
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_list_split(head, &one, &two);
	ft_merge_sort_by_name_rev(&one);
	ft_merge_sort_by_name_rev(&two);
	*list = ft_sorted_merge_by_name_rev(one, two);
}

void    ft_merge_sort_by_time(t_list **list)
{
	t_list *head;
	t_list *one;
	t_list *two;

	head = *list;
	one = (t_list*)malloc(sizeof(t_list) * 2048);
	two = (t_list*)malloc(sizeof(t_list) * 2048);
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_list_split(head, &one, &two);
	ft_merge_sort_by_time(&one);
	ft_merge_sort_by_time(&two);
	*list = ft_sorted_merge_by_time(one, two);
}

void    ft_merge_sort_by_time_rev(t_list **list)
{
	t_list *head;
	t_list *one;
	t_list *two;

	head = *list;
	one = (t_list*)malloc(sizeof(t_list) * 2048);
	two = (t_list*)malloc(sizeof(t_list) * 2048);
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_list_split(head, &one, &two);
	ft_merge_sort_by_time_rev(&one);
	ft_merge_sort_by_time_rev(&two);
	*list = ft_sorted_merge_by_time_rev(one, two);
}

void    ft_sort_mode(t_list **new)
{
	if (g_flags[2] == 0 && g_flags[4] == 0)
		ft_merge_sort_by_name(new);
	else if (g_flags[2] != 0 && g_flags[4] == 0)
		ft_merge_sort_by_name_rev(new);
	else if (g_flags[2] == 0 && g_flags[4] != 0)
		ft_merge_sort_by_time(new);
	else if (g_flags[2] != 0 && g_flags[4] != 0)
		ft_merge_sort_by_time_rev(new);
}
