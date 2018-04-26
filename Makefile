# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 10:29:59 by brel-baz          #+#    #+#              #
#    Updated: 2018/04/21 18:18:11 by brel-baz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC = ./ft_printf.c ./ft_convert.c ./ft_flag.c ./ft_itoa_base.c \
		./ft_itoa_base_up.c ./ft_flag_less.c ./ft_precision.c ./ft_convertor \
		./ft_convertor2.c ./ft_flagor.c ./ft_parser.c ./ft_cast.c \
		./ft_utoa_base.c ./ft_utoa_base_up.c ./ft_init.c ./ft_space.c \
		./ft_more.c ./ft_init_2.c ./ft_less.c ./ft_less2.c ./ft_parse_format.c \
		./ft_unicode.c
OBJ = $(addsuffix .o,$(basename $(SRC)))

all : $(NAME)

$(NAME) : $(OBJ)
		make -C libft/
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAG) $(OPTION) -c $< -o $@

clean :
		make -C libft/ clean
		rm -f $(OBJ)
fclean : clean
		make -C libft/ fclean
		rm -f $(NAME)

re : fclean all re

.PHONY : all clean fclean re
