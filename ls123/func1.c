/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:21:51 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:22:08 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char*)malloc(sizeof(*s1) * (i + 1));
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void    ft_print_usage(char c)
{
	ft_printf("/bin/ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
	ft_printf(" [file ...]\n");
	exit(1);
}

int     ft_check_in_base(char c, char *base)
{
	int i;

	i = -1;
	while (*(base + ++i))
		if (c == *(base + i))
		{
			g_flags[i] = 1;
			return (1);
		}
	return (0);
}

void    ft_reset_flags2()
{
	int i;

	i = -1;
	while (++i < 10)
		g_flags[i] = 0;
}

int     ft_check_flags(char **av)
{
	int i;
	int j;
	static char *base = "larRtofdgG";

	i = 0;
	ft_reset_flags2();
	while (*(av + ++i))
	{
		j = 0;
		if (av[i][0] != '-')
			break;
		if (!av[i][1])
			break;
		if (av[i][1] == '-' && !av[i][2])
		{
			i++;
			break;
		}
		while (av[i][++j])
			if (!ft_check_in_base(av[i][j], base))
				ft_print_usage(av[i][j]);
	}
	return (i);
}
