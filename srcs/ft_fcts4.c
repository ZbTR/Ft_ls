/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcts4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:02:31 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 18:16:51 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

void	ft_fill_link2(t_ent *list, struct stat file)
{
	list->mode = ft_itoa((int)ft_dec_to_oct(file.st_mode) % 1000);
	list->nb_liens = (unsigned long)file.st_nlink;
	list->owner = (long)file.st_uid;
	list->grp = (long)file.st_gid;
	list->taille = (long long)file.st_size;
	list->date = file.st_mtime;
	list->major = (int)MAJOR(file.st_rdev);
	list->minor = (int)MINOR(file.st_rdev);
}
