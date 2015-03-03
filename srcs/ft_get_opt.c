/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 21:05:54 by abruno            #+#    #+#             */
/*   Updated: 2015/03/03 16:15:52 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_full_opt(int *opts, char opt)
{
	if (opt == 'l')
		opts[0] = 1;
	else if (opt == 'R')
		opts[1] = 1;
	else if (opt == 'a')
		opts[2] = 1;
	else if (opt == 'r')
		opts[3] = 1;
	else if (opt == 't')
		opts[4] = 1;
	else
	{
		if (opts[5] != 2)
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(opt, 2);
			ft_putstr_fd("\nusage: ls [-Ralrt", 2);
			ft_putstr_fd("] [file ...]\n", 2);
		}
		opts[5] = 2;
	}
}

char	**ft_get_opt(char **argv, int *opts)
{
	while ((*argv) && (**argv == '-'))
	{
		(*argv)++;
		if (**argv == '\0')
		{
			(*argv)--;
			opts[5] = 1;
			return (argv);
		}
		while (**argv != '\0')
		{
			ft_full_opt(opts, **argv);
			if (opts[5] == 2)
				return (argv);
			(*argv)++;
		}
		argv++;
	}
	return (argv);
}

int		*ft_reset_opts(int *opts)
{
	int	i;

	i = 7;
	while (i < 13)
	{
		opts[i] = 0;
		i++;
	}
	return (opts);
}

void	ft_put3str(char *str1, char *str2, char *str3)
{
	ft_putstr(str1);
	ft_putstr(str2);
	ft_putstr(str3);
}
