# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdurmus <bdurmus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:57:38 by bdurmus           #+#    #+#              #
#    Updated: 2022/03/02 15:58:32 by bdurmus          ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "ft_*.c")

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) *.o
clean:
	rm -f  *.o
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
