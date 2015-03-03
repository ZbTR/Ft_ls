/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:31:20 by abruno            #+#    #+#             */
/*   Updated: 2014/11/09 17:06:21 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = 0;
	while (s1[len] != '\0')
		len++;
	s2 = (char *)malloc((len + 1) * sizeof(*s2));
	if (s2)
		s2 = ft_strcpy(s2, s1);
	return (s2);
}
