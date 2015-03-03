/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 12:57:55 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 18:11:52 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <stdio.h>

t_ent			*ft_fill_chain(int *opt, char **names, int nb)
{
	t_ent	*tmp;

	if (!names)
	{
		tmp = malloc(sizeof(t_ent));
		ft_set_mail(tmp);
		return (tmp);
	}
	if (!(*names))
	{
		*names = malloc(sizeof(char) * 2);
		(*names)[0] = '.';
		(*names)[1] = '\0';
		names[1] = NULL;
	}
	tmp = malloc(sizeof(t_ent));
	ft_set_mail(tmp);
	ft_fill_extended(tmp, names, opt, nb);
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

void			ft_fill_extended(t_ent *list, char **names, int *opts, int nb)
{
	struct stat file;

	while ((lstat(*names, &file) != -1) && (*names))
	{
		ft_fill_link(list, file, *names, nb);
		ft_layout(list, opts);
		if (opts[3] == 1)
			ft_place_linkr(list, opts);
		else
			ft_place_link(list, opts);
		while (list->next)
			list = list->next;
		list->next = malloc(sizeof(*list));
		ft_set_mail(list->next);
		list->next->prev = list;
		list = list->next;
		list->name = NULL;
		names++;
	}
	if (*names)
	{
		ft_putstr_fd("ls: ", 2);
		perror(*names);
		ft_fill_extended(list, ++names, opts, nb);
	}
}

void			ft_fill_link(t_ent *list, struct stat file, char *name, int nb)
{
	list->name = name;
	if ((file.st_mode & S_IFMT) == S_IFBLK)
		list->type = 1;
	else if ((file.st_mode & S_IFMT) == S_IFCHR)
		list->type = 2;
	else if ((file.st_mode & S_IFMT) == S_IFDIR)
	{
		if (nb == 0 || nb == 2)
			list->type = 3;
		else
			list->type = 8;
	}
	else if ((file.st_mode & S_IFMT) == S_IFIFO)
		list->type = 4;
	else if ((file.st_mode & S_IFMT) == S_IFLNK)
		list->type = 5;
	else if ((file.st_mode & S_IFMT) == S_IFREG)
		list->type = 6;
	else if ((file.st_mode & S_IFMT) == S_IFSOCK)
		list->type = 7;
	else
		list->type = 0;
	ft_fill_link2(list, file);
}

unsigned long	ft_dec_to_oct(unsigned long nb)
{
	unsigned long	rem;
	unsigned long	i;
	unsigned long	octal;

	i = 1;
	octal = 0;
	while (nb != 0)
	{
		rem = nb % 8;
		nb /= 8;
		octal += rem * i;
		i *= 10;
	}
	return (octal);
}
