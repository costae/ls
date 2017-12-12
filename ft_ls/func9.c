/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:24:20 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 16:57:43 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_find_minmax(t_list *h_h)
{
	t_list *here;
	int lmax;

	lmax = 0;
	here = h_h;
	while (here)
	{
		if (here->data.min > lmax)
			lmax = here->data.min;
		here = here->next;
	}
	return (strlen(ft_itoa(lmax)));
}

char	*ft_rdlnk(t_list *h_h)
{
	struct stat sb;
	char *linkname;
	ssize_t r;

	lstat(h_h->data.name, &sb);
	linkname = (char *)malloc(sizeof(char) * 1500);
	r = readlink(h_h->data.name, linkname, 1024);
	linkname[r] = '\0';
	return (linkname);
}

char	*ft_readlink_file(t_list *h_h, char *s)
{
	char *work;
	char *temp;

	temp = ft_strjoin(s, " -> ");
	work = ft_strjoin(temp, ft_rdlnk(h_h));
	free(temp);
	return (work);
}

int		ft_check_c_b(t_list *h_h)
{
	t_list *new;


	new = NULL;
	new = (t_list*)malloc(sizeof(t_list ) * 2048);
	new = h_h;
	while (new)
	{
		if (new->data.rights[0] == 'c' || new->data.rights[0] == 'b')
			return (1);
		new = new->next;
	}
	return (0);
}
