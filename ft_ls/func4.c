/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:23:02 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:23:33 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    ft_list_split(t_list *list, t_list **one, t_list **two)
{
	t_list *fast;
	t_list *slow;

	if (list == NULL || list->next == NULL)
	{
		*one = list;
		*two = NULL;
	}
	else
	{
		slow = list;
		fast = list->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*one = list;
		*two = slow->next;
		slow->next = NULL;
	}
}

t_list  *ft_sorted_merge_by_name(t_list *one, t_list *two)
{
	t_list *end;

	end = NULL;
	if (one == NULL)
		return (two);
	if (two == NULL)
		return (one);
	if (ft_strcmp(one->data.name, two->data.name) < 0)
	{
		end = one;
		end->next = ft_sorted_merge_by_name(one->next, two);
	}
	else
	{
		end = two;
		end->next = ft_sorted_merge_by_name(one, two->next);
	}
	return (end);
}

t_list  *ft_sorted_merge_by_name_rev(t_list *one, t_list *two)
{
	t_list *end;

	end = NULL;
	if (one == NULL)
		return (two);
	if (two == NULL)
		return (one);
	if (ft_strcmp(one->data.name, two->data.name) > 0)
	{
		end = one;
		end->next = ft_sorted_merge_by_name_rev(one->next, two);
	}
	else
	{
		end = two;
		end->next = ft_sorted_merge_by_name_rev(one, two->next);
	}
	return (end);
}

t_list  *ft_sorted_merge_by_time(t_list *one, t_list *two)
{
	t_list *end;

	end = NULL;
	if (one == NULL)
		return (two);
	if (two == NULL)
		return (one);
	if (difftime(one->data.time, two->data.time) > 0)
	{
		end = one;
		end->next = ft_sorted_merge_by_time(one->next, two);
	}
	else
	{
		end = two;
		end->next = ft_sorted_merge_by_time(one, two->next);
	}
	return (end);
}

t_list  *ft_sorted_merge_by_time_rev(t_list *one, t_list *two)
{
	t_list *end;

	end = NULL;
	if (one == NULL)
		return (two);
	if (two == NULL)
		return (one);
	if (difftime(one->data.time, two->data.time) < 0)
	{
		end = one;
		end->next = ft_sorted_merge_by_time_rev(one->next, two);
	}
	else
	{
		end = two;
		end->next = ft_sorted_merge_by_time_rev(one, two->next);
	}
	return (end);
}
