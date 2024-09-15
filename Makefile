NAME=cub3D
CC=cc
FLAGS=-Wall -Wextra -Werror
PARSING=
PART2= 
SRC=cub.c $(PARSING) $(EXEC)
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

