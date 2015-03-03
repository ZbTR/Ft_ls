/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcts3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 15:22:18 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 17:43:53 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

void	ft_putlinks_laid(t_ent *ents, int *opts)
{
	int		i;

	ft_putchar(' ');
	i = (int)ft_strlen(ft_itoa((int)ents->nb_liens));
	while (i <= opts[7])
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr((int)ents->nb_liens);
	ft_putchar(' ');
}

void	ft_putsize_laid(t_ent *ents, int *opts)
{
	int		i;

	i = (int)ft_strlen(ft_itoa((int)ents->taille));
	while (i < opts[12])
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr((int)ents->taille);
	ft_putchar(' ');
}

void	ft_putmajmin_laid(t_ent *ents, int *opts)
{
	int		i;

	i = (int)ft_strlen(ft_itoa((int)ents->major));
	while (i <= opts[10])
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(ents->major / 16);
	ft_putstr(", ");
	i = (int)ft_strlen(ft_itoa((int)ents->minor));
	while (i < opts[11])
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(ents->minor);
	ft_putchar(' ');
}

void	ft_putownergr_laid(t_ent *ents, int *opts, int nb)
{
	int		i;

	if (nb == 1)
	{
		ft_putstr(getpwuid(ents->owner)->pw_name);
		i = (int)ft_strlen(getpwuid(ents->owner)->pw_name);
		while (i <= opts[8])
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		ft_putstr(getgrgid(ents->grp)->gr_name);
		i = (int)ft_strlen(getgrgid(ents->grp)->gr_name);
		while (i <= opts[9])
		{
			ft_putchar(' ');
			i++;
		}
	}
	ft_putchar (' ');
}
