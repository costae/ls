/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:36:42 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void					ft_putadd1(int temp)
{
	if (temp > '9')
	{
		temp += 39;
		ft_putchar(temp);
	}
	else
	{
		ft_putchar(temp);
	}
}

void					ft_putaddr_fd(void *str, int fd)
{
	long int			div;
	char				temp;
	unsigned long int	n;
	int					a;

	a = 0;
	(void)fd;
	n = (unsigned long int)str;
	div = 16;
	ft_putstr("0x");
	if (str == NULL)
		ft_putstr("0");
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		if (str == NULL)
			break ;
		temp = '0' + n / div;
		ft_putadd1(temp);
		n %= div;
		div /= 16;
		a++;
	}
}

char					*ft_add1(long int div, unsigned long n,
			int a, char *s)
{
	char				temp;

	temp = 0;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			s[a] = temp;
		}
		else
			s[a] = temp;
		n %= div;
		div /= 16;
		a++;
	}
	return (s);
}

char					*ft_addlen(void *str)
{
	long int			div;
	unsigned long int	n;
	int					a;
	char				*s;

	s = (char *)malloc(sizeof(char) * 30);
	a = 0;
	n = (unsigned long int)str;
	div = 16;
	while (n / div >= 16)
		div *= 16;
	s = ft_add1(div, n, a, s);
	return (s);
}

void					ft_putaddr(void *str)
{
	g_addlen = ft_addlen(str);
	if (g_tab.width && g_tab.minus == 0)
	{
		if (g_tab.width <= ft_lenad(g_addlen))
			ft_putaddr_fd(str, 1);
		else
		{
			ft_putnch(' ', g_tab.width - ft_lenad(g_addlen));
			ft_putaddr_fd(str, 1);
		}
	}
	else if (g_tab.minus)
	{
		ft_putaddr_fd(str, 1);
		ft_putnch(' ', g_tab.width - ft_lenad(g_addlen));
	}
	else
		ft_putaddr_fd(str, 1);
}
