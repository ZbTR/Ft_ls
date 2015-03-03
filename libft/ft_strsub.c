/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:55:09 by abruno            #+#    #+#             */
/*   Updated: 2015/01/24 18:15:58 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dest;

	if (((int)len) < 0)
		return (NULL);
	dest = (char *)malloc((len + 1) * sizeof(*s));
	if (s == NULL)
		return (NULL);
	ft_strncpy(dest, &(s[start]), len);
	dest[len] = '\0';
	return (dest);
}
