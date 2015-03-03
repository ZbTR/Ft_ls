/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:48:54 by abruno            #+#    #+#             */
/*   Updated: 2014/11/03 17:15:30 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp_d;
	const char	*tmp_s;

	i = 0;
	tmp_d = dst;
	tmp_s = src;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	return (dst);
}
