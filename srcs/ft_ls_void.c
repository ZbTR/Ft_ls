/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:21:57 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 17:48:47 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

char	**ft_strtab(char **tab, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	tmp = malloc(sizeof(*tmp) * (i + 3));
	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			tmp[i] = tab[i];
			i++;
		}
	}
	tmp[i] = str;
	tmp[i + 1] = NULL;
	return (tmp);
}

char	**ft_error(char *str)
{
	ft_putstr_fd("ls: ", 2);
	perror(str);
	return (NULL);
}

char	**ft_ls_dir(char *names, int *opts)
{
	DIR				*tmp;
	struct dirent	*tmp2;
	char			**tmp3;
	char			*tmp4;

	opts = opts;
	tmp3 = NULL;
	tmp4 = 0;
	if ((tmp = opendir(names)))
	{
		while ((tmp2 = readdir(tmp)))
		{
			tmp4 = ft_strjoin(names, "/");
			tmp3 = ft_strtab(tmp3, ft_strjoin(tmp4, tmp2->d_name));
		}
		closedir(tmp);
	}
	else
	{
		ft_error(names);
		return (NULL);
	}
	return (tmp3);
}

char	*ft_getblk(char **str)
{
	int			i;
	int			j;
	struct stat	sb;
	char		*tmp;

	j = 0;
	i = 0;
	while (lstat(str[i], &sb) != -1)
	{
		j += (int)sb.st_blocks;
		i++;
	}
	tmp = malloc(sizeof(char) * ((int)ft_strlen(ft_itoa(j)) + 7));
	tmp = ft_strjoin("total ", ft_itoa(j));
	tmp = ft_strjoin(tmp, "\n");
	return (tmp);
}
