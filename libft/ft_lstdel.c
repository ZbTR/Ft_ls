/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:25:52 by abruno            #+#    #+#             */
/*   Updated: 2014/11/06 18:38:33 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst)
	{
		while ((*alst) != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			tmp = *alst;
			free(*alst);
			*alst = tmp->next;
		}
		*alst = NULL;
	}
}
