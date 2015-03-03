/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:48:57 by abruno            #+#    #+#             */
/*   Updated: 2014/11/06 15:51:31 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	if (s && f)
	{
		dst = ft_strnew(ft_strlen(s));
		i = 0;
		while (s[i] != '\0')
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
