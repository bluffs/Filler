.PHONY : clean, fclean, re, $(NAME)

NAME = jyakdi.filler
SRC = jyakdi.c ft_get_info.c ft_place.c

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
PRINTF = ft_printf_git2/libftprintf.a
CC = gcc
OPTION = -c -I./
FLAG = 

all : $(NAME)

$(NAME) : $(OBJ)
	make -Clibft
	make -Cft_printf_git2
	$(CC) -o $(NAME) $(FLAG) $(OBJ) $(LIBFT) $(PRINTF)

$(OBJ) : $(SRC)
	$(CC) $(FLAG) $(OPTION) $(SRC)

clean :
	make clean -Clibft
	make clean -Cft_printf_git2
	rm -rf $(OBJ)

fclean : clean
	make fclean -Clibft
	make fclean -Cft_printf_git2
	rm -rf $(NAME)

re : fclean all
