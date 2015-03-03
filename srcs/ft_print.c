/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:47:48 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 17:58:38 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>

char	*ft_strcut(char *str, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = malloc(sizeof(char) * end - start);
	i = 0;
	while (i + start < end)
	{
		tmp[i] = str[i + start];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_putname(char *str, t_ent *ents)
{
	if (ents->type == 6)
		ft_putstr("\033[37m");
	else if (ents->type == 3 || ents->type == 8)
		ft_putstr("\033[34m");
	else if (ents->type == 1)
		ft_putstr("\033[31m");
	else if (ents->type == 2)
		ft_putstr("\033[35m");
	else if (ents->type == 4)
		ft_putstr("\033[33m");
	else if (ents->type == 6)
		ft_putstr("\033[36m");
	else if (ents->type == 2)
		ft_putstr("\033[32m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void	ft_print(t_ent *ents, int *opts)
{
	char	*tmp;

	if (opts[0] == 1)
	{
		if (ents->type == 1)
			ft_putchar('b');
		else if (ents->type == 2)
			ft_putchar('c');
		else if (ents->type == 3 || ents->type == 8)
			ft_putchar('d');
		else if (ents->type == 4)
			ft_putchar('p');
		else if (ents->type == 5)
			ft_putchar('l');
		else if (ents->type == 6)
			ft_putchar('-');
		else if (ents->type == 7)
			ft_putchar('s');
		ft_print2(ents, opts);
	}
	tmp = ft_cutstr(ents->name, '/');
	if (tmp)
		ft_putname(tmp, ents);
	ft_putchar('\n');
}

void	ft_print2(t_ent *ents, int *opts)
{
	ft_putstr(ft_mod_convert(ents->mode));
	ft_putlinks_laid(ents, opts);
	if (getpwuid(ents->owner))
		ft_putownergr_laid(ents, opts, 1);
	else
	{
		ft_putnbr((int)(ents->owner));
		ft_putchar(' ');
	}
	if (getgrgid(ents->grp))
		ft_putownergr_laid(ents, opts, 2);
	else
	{
		ft_putnbr((int)(ents->grp));
		ft_putchar(' ');
	}
	if (ents->type != 2 && ents->type != 1)
		ft_putsize_laid(ents, opts);
	else
		ft_putmajmin_laid(ents, opts);
	ft_putstr(ft_strcut(ft_strtrim(ctime(&(ents->date))), 4, 16));
	ft_putchar(' ');
}
