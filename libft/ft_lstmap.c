/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:31:40 by abruno            #+#    #+#             */
/*   Updated: 2014/11/06 17:36:49 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;
	t_list	*prev_elem;
	t_list	*begin;
	t_list	*tmp;

	new_elem = NULL;
	prev_elem = NULL;
	begin = NULL;
	tmp = NULL;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (!(new_elem = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new_elem->next = NULL;
		if (prev_elem != NULL)
			prev_elem->next = new_elem;
		lst = lst->next;
		prev_elem = new_elem;
		if (begin == NULL)
			begin = new_elem;
	}
	return (begin);
}
