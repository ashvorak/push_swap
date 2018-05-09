# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by oshvorak          #+#    #+#              #
#    Updated: 2018/05/09 11:49:18 by oshvorak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

NAME_CH = checker

SRC =	./src/main.c \
		./src/reader.c

MLIB = make -C lib

LIB = lib/libftprintf.a

all: $(NAME_PS)

$(NAME_PS): $(SRC)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME_PS)
	
clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all
