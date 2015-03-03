#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruno <abruno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/14 15:30:26 by abruno            #+#    #+#              #
#    Updated: 2015/02/12 18:04:44 by abruno           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBA	=	./libft/libft.a
CC		= 	gcc
NAME	=	ft_ls
INCLUDES=	./includes
CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDES)
LDFLAGS	=	-L ./libft -lft
SRCS	=	srcs/ft_ls.c				\
			srcs/ft_fcts.c				\
			srcs/ft_fcts2.c				\
			srcs/ft_fcts3.c				\
			srcs/ft_fcts4.c				\
			srcs/ft_get_opt.c			\
			srcs/ft_ls_void.c			\
			srcs/ft_set_chain.c			\
			srcs/ft_print.c				\
			srcs/ft_place_link.c		\
			srcs/main.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
