NAME=cub3D
CC=cc
S=-fsanitize=address -g
FLAGS=-Wall -Wextra -Werror $(S)
PARSING=
PART2= cub_clean.c  utils1.c cub_clean.c creat_window.c init_structs.c creat_textures.c
SRC=cub.c $(PARSING) $(PART2)
OBJ=$(SRC:.c=.o)
LIBFT=./libft/libft.a
LIBFT_PATH=./libft
INCLUDES=./libft/libft.h cub3d.h
FRAMEWORKS= -framework OpenGL -framework AppKit -lmlx
LINUX= -lX11 -lXext -lXrandr
MLX_PATH = ./minilibx-linux
MLX=$(MLX_PATH)/libmlx_Linux.a

all : libf mlx $(NAME)

mlx :
	make -C $(MLX_PATH)

libf :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX) $(LINUX) -o $@

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

