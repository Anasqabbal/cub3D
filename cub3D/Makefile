NAME=cub3D
CC=cc
S=-fsanitize=address -g
FLAGS=-Wall -Wextra -Werror $(S)
PARSING=
PART2= cub_clean.c  utils1.c cub_clean.c creat_window.c init_structs.c creat_textures.c move_player.c moves.c
SRC=test2.c $(PARSING) $(PART2)
OBJ=$(SRC:.c=.o)
LIBFT=./libft/libft.a
LIBFT_PATH=./libft
LIBFT_LINUX=./libft_linux
INCLUDES=./libft/libft.h cub3d.h
FRAMEWORKS= -framework OpenGL -framework AppKit -lmlx
MLX_PATH = ./minilibx-linux
MLX=$(MLX_PATH)/libmlx_Linux.a
LINUX= -lX11 -lXext -lXrandr
SYSTEM=$(uname)

#all : libf $(NAME)

 all : libf mlx  $(NAME)

mlx :
	make -C $(MLX_PATH)

#libf :
#	make -C $(LIBFT_PATH)

libf :
	make -C $(LIBFT_LINUX)

#$(NAME) : $(OBJ)
#	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(FRAMEWORKS) -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LINUX)/libft.a  $(MLX) $(LINUX) -o $@

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

