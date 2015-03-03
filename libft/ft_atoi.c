/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:47:52 by abruno            #+#    #+#             */
/*   Updated: 2014/11/10 17:59:16 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	j = i;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + str[i] - '0';
		else if (!((str[i] == '+' || str[i] == '-') && i == j))
			break ;
		i++;
	}
	if (str[j] == '-')
		num *= -1;
	return (num);
}
