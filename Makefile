# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 09:09:09 by yrio              #+#    #+#              #
#    Updated: 2024/01/30 09:40:52 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror -g3
ARCHIVE = libft/libft.a
SRC = main.c ft_printf.c ft_printf_utils.c get_next_line.c get_next_line_utils.c \
	pipex_utils.c lst_utils.c pipex_utils2.c pipex_utils3.c

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ) $(ARCHIVE) -lm
	
$(OBJ): $(SRC)
	make bonus -C libft
	cc $(FLAGS) -g -c $(SRC)

clean:
	make clean -C libft
	rm -f prog *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus