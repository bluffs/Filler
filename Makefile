# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 08:54:34 by jyakdi            #+#    #+#              #
#    Updated: 2017/05/22 11:15:41 by jyakdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean, fclean, re, $(NAME)

NAME = jyakdi.filler
SRC = jyakdi.c ft_get_info.c ft_place.c ft_strat.c ft_place_up.c \
	ft_place_down.c ft_place_side.c ft_fill_side.c ft_tools.c ft_visualizer.c \
	ft_draw.c ft_draw2.c ft_piece.c

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLX = -lmlx -framework OpenGL -framework AppKit
CC = gcc
OPTION = -c -I./
FLAG =

all : $(NAME)

$(NAME) : $(OBJ)
	make -Clibft
	$(CC) -o $(NAME) $(FLAG) $(OBJ) $(LIBFT) $(MLX)

$(OBJ) : $(SRC)
	$(CC) $(FLAG) $(OPTION) $(SRC)

clean :
	make clean -Clibft
	rm -rf $(OBJ)

fclean : clean
	make fclean -Clibft
	rm -rf $(NAME)

re : fclean all
