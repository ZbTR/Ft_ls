/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:37:02 by abruno            #+#    #+#             */
/*   Updated: 2014/11/06 18:31:45 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordsize(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		size++;
	}
	return (size);
}

size_t	ft_countwords(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**ptr;
	size_t	nb_words;
	size_t	i;
	size_t	word_size;

	nb_words = ft_countwords(s, c);
	ptr = malloc((nb_words + 1) * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < nb_words && *s != '\0')
	{
		while (*s == c)
			s++;
		word_size = ft_wordsize(s, c);
		ptr[i] = malloc((word_size + 1) * sizeof(**ptr));
		if (ptr[i] == NULL)
			return (NULL);
		ft_strncpy(ptr[i], s, word_size);
		ptr[i][word_size] = '\0';
		s += word_size;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
