# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by oshvorak          #+#    #+#              #
#    Updated: 2018/05/21 16:25:08 by oshvorak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRC1 =	./src/main.c \
		./src/push_b.c \
		./src/sort.c \
		./src/convert_operations.c \
		./src/handle_block.c \
		./src/push_a.c \
		./src/return_base.c \
		./src/push_block.c \
		./src/clean_a.c \
		./src/print_operations.c

SRC2 =	./src/checker/main.c \
		./src/checker/checker.c \
		./src/checker/handle_flags.c \
		./src/checker/print_help.c \
		./src/checker/check_valid.c

SRC3 = 	./src/reader.c \
		./src/is_valid.c \
		./src/operations.c \
		./src/process_struct.c

MLIB = make -C lib

LIB = lib/libftprintf.a

all: $(NAME1) $(NAME2)

$(NAME1): $(SRC1)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC1) $(SRC3) $(LIB) -o $(NAME1)

$(NAME2): $(SRC2)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC2) $(SRC3) $(LIB) -o $(NAME2)

clean:
	$(MLIB) clean

fclean: clean
	rm -f $(NAME1) $(NAME2)
	$(MLIB) fclean

re: fclean all
