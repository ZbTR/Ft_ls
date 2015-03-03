/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:38:05 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 17:46:31 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>

t_ent	*ft_dirlink(t_ent *ch, t_ent *chdir)
{
	t_ent	*tmp;

	tmp = malloc(sizeof(t_ent));
	tmp->name = ch->name;
	tmp->type = 8;
	tmp->mode = ch->mode;
	tmp->nb_liens = ch->nb_liens;
	tmp->owner = ch->owner;
	tmp->grp = ch->grp;
	tmp->taille = ch->taille;
	tmp->date = ch->date;
	tmp->major = ch->major;
	tmp->minor = ch->minor;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (chdir)
	{
		tmp->prev = chdir;
		chdir->next = tmp;
		chdir = chdir->next;
	}
	else
		chdir = tmp;
	return (chdir);
}

void	ft_ls(int argc, char **argv, int nb, int *opts)
{
	t_ent	*ents;
	t_ent	*chdir;

	chdir = NULL;
	if (opts[5] == 2)
		return ;
	ents = ft_fill_chain(opts, argv, nb);
	while (ents->next && ents->name)
	{
		chdir = ft_ls2(chdir, ents, opts, nb);
		ents = ents->next;
	}
	if (chdir)
	{
		while (chdir->prev)
			chdir = chdir->prev;
		while (chdir)
		{
			ft_ls3(chdir, opts, nb, argc);
			chdir = chdir->next;
		}
	}
}

t_ent	*ft_ls2(t_ent *chdir, t_ent *ents, int *opts, int nb)
{
	char	*str;
	char	*str2;

	str = ft_cutstr(ents->name, '/');
	str2 = ft_cutstr2(ents->name, '/');
	if (ents->type == 3)
	{
		chdir = ft_dirlink(ents, chdir);
		if (nb != 2 && (opts[2] == 1 || str[0] != '.')
			&& ((str2[0] != '.' || opts[2] == 1)
				|| (str2[0] == '.' && str2[1] == '/')))
			ft_print(ents, opts);
	}
	else
	{
		if ((opts[2] == 1 || (str[0] != '.'))
			&& ((str2[0] != '.' || opts[2] == 1)
				|| (str2[0] == '.' && str2[1] == '/')))
		{
			ft_print(ents, opts);
			(opts[6])++;
		}
	}
	return (chdir);
}

void	ft_ls3(t_ent *chdir, int *opts, int nb, int argc)
{
	char	*str;
	char	**tmp;

	str = ft_cutstr(chdir->name, '/');
	tmp = ft_ls_dir(chdir->name, opts);
	if ((ft_strcmp(str, "..") != 0 && ft_strcmp(str, ".") != 0)
		|| ((ft_strcmp(str, ".") == 0) && nb == 2))
	{
		if ((((opts[6] > 0 || nb != 2) && (opts[2] == 1 || (str[0] != '.')))
			|| nb == 2) && ((argc != 1 && argc != 2) || nb != 2))
		{
			if (opts[6] > 0 || nb != 2)
				ft_putchar('\n');
			if (opts[6] > 0 || (nb == 2 && chdir->next))
				ft_put3str(chdir->name, ":\n", NULL);
		}
		if (tmp && tmp[2] && opts[0] == 1)
			ft_putstr(ft_getblk(tmp));
		if (opts[1] == 1)
			ft_ls(nb, tmp, 0, ft_reset_opts(opts));
		else
			ft_ls(nb, tmp, 1, ft_reset_opts(opts));
	}
}
