/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:25:11 by abruno            #+#    #+#             */
/*   Updated: 2014/11/09 17:09:10 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	len;
	char	*s_trim;

	while (*s != '\0' && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	len = ft_strlen(s);
	while (len > 0
			&& (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	s_trim = (char *)malloc((len + 1) * sizeof(*s_trim));
	ft_strncpy(s_trim, s, len);
	s_trim[len] = '\0';
	return (s_trim);
}
