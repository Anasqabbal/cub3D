NAME=cub3D
BONUS=cub3D_bonus
CC=cc
S= -fsanitize=address -g
FLAGS= -Wall -Wextra -Werror $(S)
PART1=  ./mandatory/part1/read_file.c
PART2=	./mandatory/part2/utils1.c ./mandatory/part2/ray_casting_utils.c ./mandatory/part2/ray_casting.c\
		./mandatory/part2/creat_window.c ./mandatory/part2/creat_element.c\
		./mandatory/part2/init_structs.c ./mandatory/part2/catch_moves.c\
		./mandatory/part2/catch_moves_utils.c ./mandatory/part2/ft_check_walls.c

PART1B = ./bonus/part1/read_file_bonus.c
PART2B = ./bonus/part2/utils1_bonus.c ./bonus/part2/ray_casting_utils_bonus.c ./bonus/part2/ray_casting_bonus.c\
		 ./bonus/part2/creat_window_bonus.c ./bonus/part2/creat_element_bonus.c\
		 ./bonus/part2/init_structs_bonus.c ./bonus/part2/catch_moves_bonus.c\
		 ./bonus/part2/catch_moves_utils_bonus.c ./bonus/part2/ft_check_walls_bonus.c\
		 ./bonus/part2/minimap_bonus.c ./bonus/part2/mouse_bonus.c

SRC=  ./mandatory/cub.c  $(PART2) $(PART1)
SRCB = ./bonus/cub_bonus.c $(PART1B) $(PART2B)
OBJ=$(SRC:.c=.o)
OBJB=$(SRCB:.c=.o)
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


$(BONUS) : $(OBJB)
	$(CC) $(FLAGS) $(OBJB) $(LIBFT) $(FRAMEWORK) $(NWMLX) -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(FRAMEWORK) $(NWMLX) -o $@

%_bonus.o : %_bonus.c
	$(CC) $(FLAGS) -c $< -o $@

%.o : %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@make -C $(LIBFT_PATH) $@
	rm -f $(OBJ)
	rm -f $(OBJB)

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