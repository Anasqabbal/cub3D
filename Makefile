NAME=cub3D
BONUS=cub3D_bonus
CC=cc
S=-fsanitize=address -g
FLAGS= -Wall -Wextra -Werror $(S)
PART1= ./part1/read_file.c
PART2=	./part2/utils1.c ./part2/ray_casting_utils.c ./part2/ray_casting.c\
		./part2/creat_window.c ./part2/creat_element.c\
		./part2/init_structs.c ./part2/catch_moves.c\
		./part2/catch_moves_utils.c ./part2/ft_check_walls.c

BONUSF= ./bonus/minimap_bonus.c ./bonus/mouse_bonus.c

SRC=  cub.c  $(PART2) $(PART1)
OBJ=$(SRC:.c=.o)
BOUNUSO=$(BONUSF:.c=.o)
LIBFT=./libft/libft.a
LIBFT_PATH=./libft
LIBFT_LINUX=./libft_linux
INCLUDES=./libft/libft.h cub3d.h
USE=$(echo anqabbal)
FRAMEWORK= -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/anqabbal/.brew/opt/glfw/lib/"
NWMLX = ./MLX42/build/libmlx42.a
MLX_PATH = ./minilibx-linux
MLX=$(MLX_PATH)/libmlx_Linux.a
LINUX= -lX11 -lXext -lXrandr
SYSTEM=$(uname)

all : libf  $(NAME)

bonus : libf  $(BONUS)

mlx :
	make -C ./MLX42/build

libf :
	make -C $(LIBFT_PATH)


$(BONUS) : $(OBJ) $(BOUNUSO)
	$(CC) $(FLAGS) $(OBJ) $(BOUNUSO) $(LIBFT) $(FRAMEWORK) $(NWMLX) -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(FRAMEWORK) $(NWMLX) -o $@


%_bonus.o : %_bonus.c
	$(CC) $(FLAGS) -c $< -o $@

%.o : %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@make -C $(LIBFT_PATH) $@
	rm -f $(OBJ)

fclean : clean
	@make -C $(LIBFT_PATH) $@
	# rm -f $(NAME)

re : fclean all

.PHONY : clean

#  all : libf mlx  $(NAME)

# libf :
# 	make -C $(LIBFT_LINUX)

# $(NAME) : $(OBJ)
# 	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LINUX)/libft.a  $(MLX) $(LINUX) -o $@