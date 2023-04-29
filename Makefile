# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:59:22 by changhyl          #+#    #+#              #
#    Updated: 2023/04/29 17:50:02 by changhyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_strncmp.c ft_atoi.c error.c hook.c fractol_utils.c sets.c fractol.c
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	 $(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ 

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:
	$(MAKE)	fclean
	$(MAKE)	all

.PHONY: all clean fclean re
