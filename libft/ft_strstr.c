/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:10:35 by abruno            #+#    #+#             */
/*   Updated: 2014/11/10 17:35:31 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if (*s2 != '\0')
	{
		len = ft_strlen(s2);
		while (ft_strncmp(s1, s2, len) != 0)
		{
			if (*s1 == '\0')
				return (NULL);
			s1++;
		}
	}
	return ((char *)s1);
}
