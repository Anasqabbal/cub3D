NAME=cub3D
CC=cc
S=-fsanitize=address -g
FLAGS=-Wall -Wextra -Werror $(S)
PARSING=
PART2= cub_clean.c
SRC=cub.c $(PARSING) $(PART2)
OBJ=$(SRC:.c=.o)
LIBFT=./libft/libft.a
LIBFT_PATH=./libft
INCLUDES=./libft/libft.h cub3d.h
FRAMEWORKS= -framework OpenGL -framework AppKit

all : libf $(NAME)

libf :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -lmlx $(FRAMEWORKS) -o $@


%.o : %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@make -C $(LIBFT_PATH) $@
	rm -f $(OBJ)

fclean : clean
	@make -C $(LIBFT_PATH) $@
	rm -f $(NAME)

re : fclean all

.PHONY : clean

