/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:22:36 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 17:42:55 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

t_ent	*ft_ls1r(t_ent *ent, t_ent **chdir, int *opt, int nb)
{
	while (ent->next)
		ent = ent->next;
	while (ent->prev && ent->name)
	{
		if (ent->type == 3)
		{
			*(chdir) = ft_dirlink(ent, *(chdir));
			if (nb != 0)
				ft_print(ent, opt);
		}
		else
		{
			ft_print(ent, opt);
			(opt[6])++;
		}
		ent = ent->next;
	}
	if (*(chdir))
	{
		while ((*(chdir))->prev)
			*(chdir) = (*(chdir))->prev;
		ent = *(chdir);
	}
	return (ent);
}

void	ft_remplis(int *c)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		c[i] = 3;
		i++;
	}
	while (i < 14)
	{
		c[i] = 0;
		i++;
	}
}

void	ft_set_mail(t_ent *mail)
{
	mail->name = NULL;
	mail->mode = NULL;
	mail->prev = NULL;
	mail->next = NULL;
}

void	ft_layout(t_ent *list, int *opt)
{
	struct passwd	*tmp;
	struct group	*tmp2;

	if (opt[7] < (int)ft_strlen(ft_itoa((int)list->nb_liens)))
		opt[7] = (int)ft_strlen(ft_itoa((int)list->nb_liens));
	tmp = getpwuid(list->owner);
	if (tmp && opt[8] < (int)ft_strlen(getpwuid(list->owner)->pw_name))
		opt[8] = (int)ft_strlen(getpwuid(list->owner)->pw_name);
	tmp2 = getgrgid(list->grp);
	if (tmp2 && opt[9] < (int)ft_strlen(getgrgid(list->grp)->gr_name))
		opt[9] = (int)ft_strlen(getgrgid(list->grp)->gr_name);
	if (list->type == 1 || list->type == 2)
	{
		if (opt[10] < (int)ft_strlen(ft_itoa((int)list->major)))
			opt[10] = (int)ft_strlen(ft_itoa((int)list->major));
		if (opt[11] < (int)ft_strlen(ft_itoa((int)list->minor)))
			opt[11] = (int)ft_strlen(ft_itoa((int)list->minor));
	}
	else
	{
		if (opt[12] < (int)ft_strlen(ft_itoa((int)list->taille)))
			opt[12] = (int)ft_strlen(ft_itoa((int)list->taille));
		if (opt[12] < opt[10] + opt[11] + 2)
			opt[12] = opt[10] + opt[11] + 2;
	}
}
