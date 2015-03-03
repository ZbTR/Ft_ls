/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:47:46 by abruno            #+#    #+#             */
/*   Updated: 2014/11/13 18:31:46 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	if (!(s = (char *)malloc((len + 1) * sizeof(*s))))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	s[len] = '\0';
	while (n >= 10)
	{
		s[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	s[len - 1] = n + '0';
	return (s);
}
