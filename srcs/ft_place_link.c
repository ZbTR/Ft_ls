/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:29:22 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 17:54:54 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

void	ft_place_link(t_ent *list, int *opts)
{
	t_ent	*tmp;

	tmp = list;
	if (opts[4] == 1)
	{
		while (list->prev && (tmp->date - list->prev->date) > 0)
			list = list->prev;
	}
	else
	{
		while (list->prev && (ft_strcmp(list->prev->name, tmp->name) > 0))
			list = list->prev;
	}
	if (tmp != list)
		ft_place_link2(list, tmp);
}

void	ft_place_link2(t_ent *list, t_ent *tmp)
{
	tmp->prev->next = NULL;
	tmp->next = list;
	if (list->prev)
	{
		tmp->prev = list->prev;
		tmp->prev->next = tmp;
	}
	else
		tmp->prev = NULL;
	list->prev = tmp;
}

void	ft_place_linkr(t_ent *list, int *opts)
{
	t_ent	*tmp;

	tmp = list;
	if (opts[4] == 1)
	{
		while (list->prev && (tmp->date - list->prev->date) <= 0)
			list = list->prev;
	}
	else
	{
		while (list->prev && (ft_strcmp(list->prev->name, tmp->name) < 0))
			list = list->prev;
	}
	if (tmp != list)
		ft_place_linkr2(list, tmp);
}

void	ft_place_linkr2(t_ent *list, t_ent *tmp)
{
	tmp->prev->next = NULL;
	tmp->next = list;
	if (list->prev)
	{
		tmp->prev = list->prev;
		tmp->prev->next = tmp;
	}
	else
		tmp->prev = NULL;
	list->prev = tmp;
}
