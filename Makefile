# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 14:40:39 by dgrandin          #+#    #+#              #
#    Updated: 2023/07/04 17:29:59 by mlangloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FT_PRINTF_FILE = libftprintf.a
FT_PRINTF_PATH = ft_printf/
FT_PRINTF_LIB = $(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF_FILE))
FT_PRINTF_EX = $(FT_PRINTF_LIB)

LIBFT_FILE = libft.a
LIBFT_PATH = Libft/
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
LIBFT_EX = $(LIBFT_LIB)

NAME = minishell
CC = gcc -Wall -Wextra -Werror -g3
SRC = minishell.c cd.c pwd.c env.c export.c manage_cmd.c manage_builtin.c environ.c environ_utils.c manage_redirection.c parsing.c parsing2.c parsing3.c parse_utils.c make_redirection.c manage_cmd_sub.c add_redirect.c utils.c export_sub.c sub_environ.c manage_cmd_sub_sub.c utils2.c minishell_sub.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -sC $(LIBFT_PATH)
	make -sC $(FT_PRINTF_PATH)
	$(CC) $(OBJ) $(LIBFT_EX) $(FT_PRINTF_EX) -o $(NAME) -lreadline

clean:
	rm -f *.o

fclean: clean
	make fclean -sC $(LIBFT_PATH)
	make fclean -sC $(FT_PRINTF_PATH)
	rm -f $(NAME)

re:	fclean all
