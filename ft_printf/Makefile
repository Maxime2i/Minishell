# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 14:40:39 by dgrandin          #+#    #+#              #
#    Updated: 2023/04/13 14:40:41 by dgrandin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -Wall -Wextra -Werror
NOR = norminette -R CheckForbiddenSourceHeader
SRC = ft_printf.c ft_p.c ft_string.c ft_hex.c ft_itoa.c ft_nbr.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
