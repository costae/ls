/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:34:32 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:48:40 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include "printfcic/printf.h"

# define PAL1 int l_max; int u_max; int gr_max; int s_max; int d_max; char *s;
# define PAL12 ft_show_blocks(h_h); l_max = ft_find_lmax(h_h);
# define PAL13 u_max = ft_find_umax(h_h); gr_max = ft_find_gmax(h_h);
# define PAL14 s_max = ft_find_smax(h_h);d_max = ft_date_max(h_h);
# define S1 struct passwd   *pw; struct group *gr; struct stat mstat;

# define PINW t_list *new; int i, n, m, j = -1, k = -1, red = 0, temp_c = 0;
# define PINW2 int count; char **s; char *color; int *arr;
# define PINW3 i = ft_get_winsize(h_h); n = ft_find_nmax(h_h); m =i/(n+1);
# define PINW4 count = ft_count_inlist(h_h); new = h_h;
# define PINW5 s = (char**)malloc(sizeof(char*) * (count + 50));
# define PINW6 color = (char*)malloc(sizeof(char) * (count + 50));

# define ASD s[count] = NULL;arr=(int*)malloc(50+sizeof(int)*m);temp_c = count;
# define SAD (temp_c > count / m) ? arr[k] = count / m + 1 : arr[k] == temp_c;
# define DAS temp_c = temp_c - count / m - 1;
# define NAS ft_corect1(new, s, color, j); ASD;

# define PALP char *b = NULL;
# define GRAY		"\x1b[31m"
# define GREEN		"\e[1;32m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\e[0;33m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"
# define L_BLUE		"\e[1;34m"
# define BG_RED		"\x1B[43m"
# define BG_DEFAULT "\x1B[49m"

typedef struct			s_data
{
	char*			name;
	char*			owner;
	char*			group;
	char*			rights;
	char*			link;
	char*			fortime;
	int				block;
	int				rdev;
	int				nlinks;
	uid_t			uid;
	gid_t			gid;
	int				size;
	time_t			time;
	time_t			atime;
	int32_t			maj;
	int32_t			min;
	int				total;
}					t_data;

typedef struct			s_list
{
	t_data				data;
	char*				home;
	int					ord;
	struct s_list		*next;
}						t_list;

int					g_flags[10];
t_list				*g_fhead;
t_list				*g_fnew;
int					g_fflag;
int					g_notfound;
int					g_first;
t_list				*g_htemp;
t_list				*g_ttemp;
int					g_file;
int					g_rec;
int					g_j;

char				*ft_strdup(const char *s);
void    			ft_print_usage(char c);
int     			ft_check_in_base(char c, char *base);
void    			ft_reset_flags2();
int					ft_check_flags(char **av);
char				*ft_strjoin(char const *s1, char const *s2);
short				is_ok(char c, char ok);
int					get_count(char const *str, char ok);
int					get_size(char const *str, int i, char ok);
char				**ft_strsplit(char const *str, char ok);
char				ft_ext_att(const char *namef);
char				*ft_rights(const char *namef);
void				ft_update_data(t_data *data, char *path);
void				ft_push_to_list(char *namef, t_list **new, int n);
void				ft_list_split(t_list *list, t_list **one, t_list **two);
t_list				*ft_sorted_merge_by_name(t_list *one, t_list *two);
t_list				*ft_sorted_merge_by_name_rev(t_list *one, t_list *two);
t_list				*ft_sorted_merge_by_time(t_list *one, t_list *two);
t_list				*ft_sorted_merge_by_time_rev(t_list *one, t_list *two);
void				ft_merge_sort_by_name(t_list **list);
void				ft_merge_sort_by_name_rev(t_list **list);
void				ft_merge_sort_by_time(t_list **list);
void				ft_merge_sort_by_time_rev(t_list **list);
void				ft_sort_mode(t_list **new);
char				*ft_find_path(const char *str, const char *source);
char				*ft_format_path(const char *path);
int					ft_check_a(char *s);
void				ft_show_blocks(t_list *here);
int					ft_find_lmax(t_list *h_h);
int					ft_find_umax(t_list *h_h);
int					ft_find_gmax(t_list *h_h);
int					ft_find_smax(t_list *h_h);
int					ft_date_max(t_list *h_h);
void				ft_print_insize(char *str, int n);
void				ft_print_insize2(char *str, int n);
void				ft_print_color(const char *s, char t);
void				ft_print_forsize(char *str, int n, char t);
void				ft_print_time(time_t our_time, int date_max);
int					ft_find_majmax(t_list *h_h);
int					ft_find_minmax(t_list *h_h);
char				*ft_rdlnk(t_list *h_h);
char				*ft_readlink_file(t_list *h_h, char *s);
int					ft_check_c_b(t_list *h_h);
void				ft_print_as_list(t_list *h_h);
void				ft_print_as_list2(t_list *h_h);
void				ft_print_error(int er, const char *str);
int					ft_check_ispoint(char *s);
size_t				ft_find_nmax(t_list *h_h);
int					ft_get_winsize(t_list *h_h);
int					ft_count_inlist(t_list *h_h);
void				ft_print_inwin(t_list *h_h);
int					ft_show_inside(const char *str);
int					ft_file_exist (char *filename);
void				show_recursively(t_list **head);
void				ft_show_folders();
void				ft_check_exist(char **av);
void				ft_print_files(t_list *list);
void				ft_show_files(char **av);
int					main(int ac, char **av);
void				ft_putinlocal(struct stat fileStat, char *local);
void				ft_free_the_list(t_list **fhead);
void				ft_print_as_list1_part1(t_list *h_h, int l_max, int u_max,
		int gr_max);
void				ft_print_as_list_part2(t_list *h_h, int s_max, int d_max,
		char *s);

#endif
