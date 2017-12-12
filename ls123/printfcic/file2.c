/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:52 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:50 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			rec2(long long int n, int base, char *str, int *i)
{
	if (n == 0)
		return ;
	rec2(n / base, base, str, i);
	str[(*i)++] = "0123456789ABCDEF"[n % base * (1 - 2 * (n < 0))];
}

char				*ft_itoa_base2(long long int v, int b)
{
	char			*str;
	int				i;

	str = (char *)malloc(sizeof(char) * 64);
	i = 0;
	if (v == 0)
		str[i++] = '0';
	rec2(v, b, str, &i);
	str[i] = '\0';
	return (str);
}

static void			urec2(unsigned long long int n,
		int base, char *str, int *i)
{
	if (n == 0)
		return ;
	urec2(n / base, base, str, i);
	str[(*i)++] = "0123456789ABCDEF"[n % base];
}

char				*ft_utoa_base2(unsigned long long int v, int b)
{
	char			*str;
	int				i;

	str = (char *)malloc(sizeof(char) * 64);
	i = 0;
	if (v == 0)
		str[i++] = '0';
	urec2(v, b, str, &i);
	str[i] = '\0';
	return (str);
}
