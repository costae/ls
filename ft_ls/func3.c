/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:22:50 by cmiron            #+#    #+#             */
/*   Updated: 2017/03/04 15:22:55 by cmiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char   ft_ext_att(const char *namef)
{
	acl_t acl = NULL;
	acl_entry_t dummy;
	ssize_t xattr;
	char str[10];

	xattr = 0;
	acl = acl_get_link_np(namef, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(namef, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	str[1] = '\0';
	if (xattr > 0)
		str[0] = '@';
	else if (acl != NULL)
		str[0] = '+';
	else
		str[0] = 0;
	return (str[0]);
}

void	ft_putinlocal(struct stat fileStat, char *local)
{
	local[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
	local[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
	local[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
	local[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
	local[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
	local[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
	local[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
	local[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
	local[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
}

char    *ft_rights(const char *namef)
{
	char *local;
	struct stat fileStat;

	lstat(namef, &fileStat);
	local = (char *)malloc(sizeof(char) * 2048);
	local[0] = (S_ISLNK(fileStat.st_mode)) ? 'l' : '-';
	if (local[0] != 'l')
		local[0] = (S_ISDIR(fileStat.st_mode)) ? 'd' : '-';
	ft_putinlocal(fileStat, local);
	if (local[0] == '-')
		local[0] = (S_ISCHR(fileStat.st_mode)) ? 'c' : '-';
	if (local[0] == '-')
		local[0] = (S_ISBLK(fileStat.st_mode)) ? 'b' : '-';
	if (local[0] == '-')
		local[0] = (S_ISFIFO(fileStat.st_mode)) ? 'p' : '-';
	if (local[0] == '-')
		local[0] = (S_ISREG(fileStat.st_mode)) ? '-' : '-';
	if (local[0] == '-')
		local[0] = (S_ISSOCK(fileStat.st_mode)) ? 's' : '-';
	local[10] = ft_ext_att(namef);
	if (local[10 != 0])
		local[11] = '\0';
	return (local);
}

void    ft_update_data(t_data *data, char *path)
{
	S1;
	lstat(path, &mstat);
	data->rights = ft_rights(path);
	data->nlinks = (int)mstat.st_nlink;
	data->uid = mstat.st_uid;
	data->gid = mstat.st_gid;
	pw = getpwuid(data->uid);
	gr = getgrgid(data->gid);
	if (pw && pw->pw_name)
		data->owner = strdup(pw->pw_name);
	else
		data->owner = ft_itoa((int)data->uid);
	if (gr && gr->gr_name)
		data->group = strdup(gr->gr_name);
	else
		data->group = ft_itoa((int)data->gid);
	data->block = (int)mstat.st_blocks;
	data->rdev = (int)mstat.st_rdev;
	data->size = (int)mstat.st_size;
	data->time = mstat.st_ctime;
	data->atime = mstat.st_atime;
	data->fortime = strdup(ctime(&mstat.st_ctime) + 4);
	data->fortime[12] = 0;
	data->min = (int)minor(mstat.st_rdev);
	data->maj = (int)major(mstat.st_rdev);
}

void    ft_push_to_list(char *namef, t_list **new, int n)
{
	t_list *create;
	t_data info;

	info.name = strdup(namef);
	ft_update_data(&info, namef);
	create = (t_list *)malloc(sizeof(t_list ) * 2048);
	create->data = info;
	create->ord = n;
	create->home = ft_strdup(".");
	if (*new)
		create->next = (*new);
	*new = create;
}
