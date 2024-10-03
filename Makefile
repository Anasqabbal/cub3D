NAME=cub3D
CC=cc
S=-fsanitize=address -g
FLAGS=-Wall -Wextra -Werror $(S)
PART2= ./part2/the_circle.c  ./part2/utils1.c  ./part2/ray_casting.c cub_clean.c  utils1.c cub_clean.c creat_window.c init_structs.c creat_textures.c move_player.c moves.c ft_check_walls.c
SRC=  cub.c $(PARSING) $(PART2)
OBJ=$(SRC:.c=.o)
LIBFT=./libft/libft.a
LIBFT_PATH=./libft
LIBFT_LINUX=./libft_linux
INCLUDES=./libft/libft.h cub3d.h
# FRAMEWORKS= -framework OpenGL -framework AppKit -lmlx
USER=$(echo ($USER))
FRAMEWORK= -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
NWMLX = ./MLX42/build/libmlx42.a
MLX_PATH = ./minilibx-linux
MLX=$(MLX_PATH)/libmlx_Linux.a
LINUX= -lX11 -lXext -lXrandr
SYSTEM=$(uname)

all : libf  $(NAME)

#  all : libf mlx  $(NAME)

mlx :
	make -C ./MLX42/build

libf :
	make -C $(LIBFT_PATH)

# libf :
# 	make -C $(LIBFT_LINUX)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(FRAMEWORK) $(NWMLX) -o $@

# $(NAME) : $(OBJ)
# 	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LINUX)/libft.a  $(MLX) $(LINUX) -o $@

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

