/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruno <abruno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:12:17 by abruno            #+#    #+#             */
/*   Updated: 2015/02/12 18:20:48 by abruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define MINORBITS 20
# define MINORMASK ((1U << MINORBITS) - 1)
# define MAJOR(dev) ((unsigned int) ((dev) >> MINORBITS))
# define MINOR(dev) ((unsigned int) ((dev) & MINORMASK))
# define MKDEV(ma,mi) (((ma) << MINORBITS) | (mi))
# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>

typedef struct	s_en
{
	char		*name;
	int			type;
	char		*mode;
	u_long		nb_liens;
	long		owner;
	long		grp;
	long long	taille;
	time_t		date;
	int			major;
	int			minor;
	int			blk;
	struct s_en	*prev;
	struct s_en	*next;
}				t_ent;

void			ft_ls(int argc, char **argv, int nb, int *opts);
t_ent			*ft_ls1(t_ent *ent, t_ent **chdir, int *opt, int nb);
t_ent			*ft_ls1r(t_ent *ent, t_ent **chdir, int *opt, int nb);
t_ent			*ft_ls2(t_ent *chdir, t_ent *ents, int *opts, int nb);
void			ft_ls3(t_ent *chdir, int *opts, int nb, int argc);
char			**ft_ls_dir(char *names, int *opts);
char			**ft_get_opt(char **argv, int *opts);
int				*ft_reset_opts(int *opts);
t_ent			*ft_fill_chain(int *opt, char **names, int nb);
void			ft_fill_extended(t_ent *list, char **names, int *opts, int nb);
void			ft_fill_link(t_ent *list, struct stat file, char *name, int nb);
void			ft_fill_link2(t_ent *list, struct stat file);
u_long			ft_dec_to_oct(unsigned long nb);
void			ft_print(t_ent *ents, int *opts);
void			ft_print2(t_ent *ents, int *opts);
char			*ft_cutstr(char *str, char c);
char			*ft_cutstr2(char *str, char c);
void			ft_remplis(int *c);
void			ft_set_mail(t_ent *mail);
t_ent			*ft_dirlink(t_ent *ch, t_ent *chdir);
void			ft_place_link(t_ent *list, int *opts);
void			ft_place_link2(t_ent *list, t_ent *tmp);
void			ft_place_linkr(t_ent *list, int *opts);
void			ft_place_linkr2(t_ent *list, t_ent *tmp);
void			ft_remplis(int *c);
void			ft_set_mail(t_ent *mail);
char			*ft_mod_convert(char *mod);
void			ft_mod_convert2(char *mod, char *tmp, int i);
void			ft_layout(t_ent *list, int *opt);
void			ft_putlinks_laid(t_ent *ents, int *opts);
void			ft_putownergr_laid(t_ent *ents, int *opts, int nb);
void			ft_putsize_laid(t_ent *ents, int *opts);
void			ft_putmajmin_laid(t_ent *ents, int *opts);
void			ft_put3str(char *str1, char *str2, char *str3);
char			*ft_getblk(char **str);
void			ft_putname(char *str, t_ent *ents);

#endif
