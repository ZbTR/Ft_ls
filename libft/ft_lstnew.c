/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:19:33 by abruno            #+#    #+#             */
/*   Updated: 2015/01/24 18:15:05 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;

	if (!content)
	{
		if (!(lst = (t_list *)ft_memalloc(sizeof(t_list))))
			return (NULL);
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		return (lst);
	}
	if (!(lst = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(lst->content = ft_memalloc(content_size)))
	{
		free(lst);
		return (NULL);
	}
	ft_memcpy(lst->content, content, content_size);
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
