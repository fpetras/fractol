# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpetras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/04 09:42:02 by fpetras           #+#    #+#              #
#    Updated: 2018/04/13 17:07:01 by fpetras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	  fractals.c \
	  mandelbrot.c \
	  julia.c \
	  burningship.c \
	  tricorn.c \
	  web.c \
	  keys.c \
	  mouse.c \
	  zoom.c \
	  utilities.c \
	  ft_strcasecmp.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

MLXFLAGS = libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a $(MLXFLAGS)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
