# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:09:09 by yrio              #+#    #+#              #
#    Updated: 2024/01/29 17:22:54 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror -g3 -s -fsanitize-address
ARCHIVE = libft/libft.a
SRC = main.c ft_printf.c ft_printf_utils.c get_next_line.c get_next_line_utils.c \
	pipex_utils.c lst_utils.c pipex_utils2.c pipex_utils3.c

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(ARCHIVE) -lm
#$(FLAGS)
	
$(OBJ): $(SRC)
	make bonus -C libft
	cc -g -c $(SRC)
#$(FLAGS)

clean:
	make clean -C libft
	rm -f prog *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus