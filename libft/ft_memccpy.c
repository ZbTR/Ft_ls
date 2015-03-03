/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:27:55 by abruno            #+#    #+#             */
/*   Updated: 2014/11/03 19:17:34 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (tmp_d[i] == c)
			return (tmp_d + i + 1);
		i++;
	}
	return (NULL);
}
