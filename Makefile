# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bagh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 16:41:27 by ael-bagh          #+#    #+#              #
#    Updated: 2020/01/02 16:41:34 by ael-bagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
OUTPUT=*.o

SRC=	ft_printf.c				\
		ft_printf.h				\
		ft_printf_lib.c			\
		ft_treating_c.c			\
		ft_treating_d.c			\
		ft_treating_p.c			\
		ft_treating_s.c			\
		ft_treating_u.c			\
		ft_treating_x.c			\


all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
