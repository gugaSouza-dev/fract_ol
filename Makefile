# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 13:04:11 by gusouza-          #+#    #+#              #
#    Updated: 2022/11/15 22:12:18 by gusouza-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
SRC		= fractol.c render.c events.c mandelbrot.c julia.c
LIBFT	= ./libft
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Wextra -Werror

all:	$(NAME) $(OBJ)

$(NAME): $(OBJ)
	echo creating libftprintf library....
	$(MAKE) -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT)/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	echo "$(NAME) created successfully!!!"
	$(MAKE) clean

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 