/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:45:09 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 17:13:18 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

char	*ft_mod_convert(char *mod)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * 10);
	while (i < 3)
	{
		ft_mod_convert2(mod, tmp, i);
		tmp += 3;
		i++;
	}
	tmp[0] = '\0';
	return (tmp - 9);
}

void	ft_mod_convert2(char *mod, char *tmp, int i)
{
	if ((mod[0 + i]) && (mod[0 + i] == '0'))
		ft_strncpy(tmp, "---", 3);
	else if (mod[0 + i] == '1')
		ft_strncpy(tmp, "--x", 3);
	else if (mod[0 + i] == '2')
		ft_strncpy(tmp, "-w-", 3);
	else if (mod[0 + i] == '3')
		ft_strncpy(tmp, "-wx", 3);
	else if (mod[0 + i] == '4')
		ft_strncpy(tmp, "r--", 3);
	else if (mod[0 + i] == '5')
		ft_strncpy(tmp, "r-x", 3);
	else if (mod[0 + i] == '6')
		ft_strncpy(tmp, "rw-", 3);
	else if (mod[0 + i] == '7')
		ft_strncpy(tmp, "rwx", 3);
}

char	*ft_cutstr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c)
		i--;
	if (i > 0)
		return (str + 1 + i);
	return (str);
}

char	*ft_cutstr2(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c)
		i--;
	i--;
	while (str[i] != c)
		i--;
	if (i > 0)
		return (str + 1 + i);
	return (str);
}
