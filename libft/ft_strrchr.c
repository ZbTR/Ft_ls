/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:05:12 by abruno            #+#    #+#             */
/*   Updated: 2014/11/09 17:08:13 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*occ;

	i = 0;
	occ = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			occ = (char *)&str[i];
		i++;
	}
	if (str[i] == c)
		occ = (char *)&str[i];
	if (occ != NULL)
		return (occ);
	else
		return (0);
}
