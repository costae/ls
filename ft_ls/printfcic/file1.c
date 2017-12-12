/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:34:51 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:35:04 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char		*ft_strrev(char *str)
{
	int		i;
	char	temp;
	int		j;

	j = ft_strlen(str);
	i = 0;
	while (i < j / 2)
	{
		temp = str[i];
		str[i] = str[j - i - 1];
		str[j - i - 1] = temp;
		i++;
	}
	return (str);
}

char		*ft_itoa_base(unsigned long long nb, size_t base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 75);
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = "0123456789abcdef"[nb % base];
		nb = nb / base;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
