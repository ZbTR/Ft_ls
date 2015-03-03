/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:32:28 by abruno            #+#    #+#             */
/*   Updated: 2015/02/11 18:27:22 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		*opts;

	opts = malloc(sizeof(int) * 14);
	ft_remplis(opts);
	argv = ft_get_opt(argv + 1, opts);
	ft_ls(argc, argv, 2, opts);
	return (0);
}
