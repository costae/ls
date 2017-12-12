/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:37:50 by cmiron            #+#    #+#             */
/*   Updated: 2017/01/25 16:37:57 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>

# define FT_ABS(a) (a < 0 ? -a : a)
# define IMAX 2147483647
# define IMIN -2147483648

typedef struct		s_tab
{
	int				punct;
	int				minus;
	int				plus;
	int				space;
	int				htag;
	int				zero;
	int				width;
	int				prec;
	char			spec;
	int				length;
}					t_tb;

signed long long	g_i;
unsigned long long	g_ui;
t_tb				g_tab;
int					g_n;
char				g_c;
char				*g_s;
wchar_t				g_wc;
wchar_t				*g_ws;
void				*g_ps;
int					g_print;
char				*g_addlen;

int					ft_isascii(int c);
int					ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strrev(char *str);
char				*ft_itoa_base(unsigned long long nb, size_t base);
void				ft_putvv8(unsigned long long nb, int nbl);
void				ft_sasati(unsigned long long int nb);
void				ft_putnbr2(va_list ap);
void				ft_putnbr1(va_list ap);
void				ft_putnn(va_list ap);
void				ft_putnbr3(va_list ap);
void				ft_putnbr4(va_list ap);
void				ft_putnbr5(va_list ap);
void				ft_putx11(char *str);
void				ft_putx12(char *str);
void				ft_putx13(char *str);
void				ft_putx1(char *str);
void				ft_putx2(char *str);
void				ft_putx3(char *str);
void				ft_putx4(char *str);
void				ft_putx5(char *str);
void				ft_putstr2(char *str);
void				ft_putstr3(char *str);
char				*ft_utoa(unsigned long long int n);
void				ft_write(char *str, int n);
void				ft_putstr4(char *str);
void				ft_putnstr(char *str, int n);
void				ft_putnbr8(va_list ap);
void				ft_putnbr9(va_list ap);
void				ft_putnbr6(va_list ap);
void				ft_putnbr7(va_list ap);
void				ft_putproc(void);
void				ft_putvv1(unsigned long long nb);
void				ft_putvv21(unsigned long long nb, int nbl);
void				ft_putvv22(unsigned long long nb, int nbl);
void				ft_putvv23(unsigned long long nb, int nbl);
void				ft_putvv2(unsigned long long nb, int nbl);
void				ft_putvv31(unsigned long long nb, int nbl);
void				ft_putvv32(unsigned long long nb, int nbl);
void				ft_putvv33(unsigned long long nb, int nbl);
void				ft_putvv3(unsigned long long nb, int nbl);
void				ft_putvv41(unsigned long long nb, int nbl);
void				ft_putvv42(unsigned long long nb, int nbl);
void				ft_putvv43(unsigned long long nb, int nbl);
void				ft_putvv4(unsigned long long nb, int nbl);
void				ft_putvv51(unsigned long long nb, int nbl);
void				ft_putvv52(unsigned long long nb, int nbl);
void				ft_putvv53(unsigned long long nb, int nbl);
void				ft_putvv5(unsigned long long nb, int nbl);
void				ft_putvv6(unsigned long long nb, int nbl);
void				ft_putvv7(unsigned long long nb, int nbl);
char				*ft_itoa_base2(long long int v, int b);
char				*ft_utoa_base2(unsigned long long int v, int b);
unsigned long int	ft_ok(void *str);
void				ft_putxx11(char *str);
void				ft_putxx12(char *str);
void				ft_putxx13(char *str);
void				ft_putxx14(char *str);
void				ft_putxx1(char *str);
void				ft_putxx2(char *str);
void				ft_putxx3(char *str);
void				ft_putxx41(char *str);
void				ft_putxx42(char *str);
void				ft_putxx4(char *str);
void				ft_puto1(char *str);
void				ft_puto21(char *str);
void				ft_puto22(char *str);
void				ft_puto23(char *str);
void				ft_puto24(char *str);
void				ft_puto2(char *str);
void				ft_puto3(char *str);
void				ft_puto4(char *str);
void				ft_puto51(char *str);
void				ft_puto52(char *str);
void				ft_putnn1(long long nb);
void				ft_putnn21(long long nb, int nbl);
void				ft_putnn22(long long nb, int nbl);
void				ft_putnn23(long long nb, int nbl);
void				ft_putnn2(long long nb, int nbl);
void				ft_putnn31(long long nb, int nbl);
void				ft_putnn32(long long nb, int nbl);
void				ft_putnn33(long long nb, int nbl);
void				ft_putnn3(long long nb, int nbl);
void				ft_putnn41(long long nb, int nbl);
void				ft_putnn42(long long nb, int nbl);
void				ft_putnn43(long long nb, int nbl);
void				ft_putnn4(long long nb, int nbl);
void				ft_putnn51(long long nb, int nbl);
void				ft_putnn52(long long nb, int nbl);
void				ft_putnn53(long long nb, int nbl);
void				ft_putnn5(long long nb, int nbl);
void				ft_putnn6(long long nb, int nbl);
void				ft_putnn7(long long nb, int nbl);
void				ft_putnn8(long long nb, int nbl);
void				ft_putss1(char *str, int i);
void				ft_putss2(char *str, int i);
void				ft_putss3(char *str, int i);
void				ft_putss4(char *str, int i);
void				ft_putss5(char *str, int i);
void				ft_putchar_fd(int c, int fd);
void				ft_putchar(char c);
int					ft_lenad(char *str);
void				ft_putcharsimple(char c);
void				ft_putnch(char c, int n);
void				ft_putwstr2(wchar_t *str);
void				ft_putnwstr2(wchar_t *str, int n);
int					ft_isdigit(char c);
int					ft_isdigit1(char c);
int					ft_wstrlen(wchar_t *s);
void				ft_putwstr1(wchar_t *str);
void				ft_putcharprec(char c);
int					ft_nblen(long long int nb);
void				ft_putstr(char *str);
char				*ft_stritoa(char *str, int len, unsigned long long unl,
		int negative);
char				*ft_addlen(void *str);
void				ft_putaddr(void *str);
void				ft_putss6(char *str, int i);
void				ft_putss7(char *str, int i);
void				ft_putstr1(char *str);
void				ft_putnb(signed long long int nb);
int					ft_printf(const char *fmt, ...);
int					ft_natoi(const char *str);
void				ft_refresh();
int					ft_islen(char c);
int					ft_search(const char *fmt, int i);
void				ft_reg(const char *fmt);
char				*ft_itoa(long long int n);

#endif
