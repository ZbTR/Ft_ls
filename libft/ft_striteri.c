/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:42:38 by abruno            #+#    #+#             */
/*   Updated: 2014/11/06 15:44:16 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	index;

	if (s && f)
	{
		index = 0;
		while (*s)
		{
			f(index, s);
			index++;
			s++;
		}
	}
}
