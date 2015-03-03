/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:00:33 by abruno            #+#    #+#             */
/*   Updated: 2014/11/06 13:10:56 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	size_t		i;
	char		*tmp_d;
	char		*tmp_s;
	const char	*tmp;

	i = 0;
	tmp_d = dst;
	tmp = src;
	tmp_s = malloc(sizeof(char) * n);
	while (i < n)
	{
		tmp_s[i] = tmp[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	free(tmp_s);
	return (dst);
}
