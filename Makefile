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
		 ./bonus/part2/minimap_bonus.c ./bonus/part2/mouse_bonus.c ./bonus/part2/minimap_utils_bonus.c

SRC=  ./mandatory/cub.c  $(PART2) $(PART1)
SRCB = ./bonus/cub_bonus.c $(PART1B) $(PART2B)
OBJ=$(SRC:.c=.o)
OBJB=$(SRCB:.c=.o)
LIBFT=./libft
INCLUDES= ./mandatory/cub3d.h
INCLUDESB= ./bonus/cub3d_bonus.h
FRAMEWORK= -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLX = ./MLX42/build

all : mlx libf  $(NAME)

bonus : mlx libf $(BONUS)

mlx :
	make -C $(MLX)

libf :
	@make -C $(LIBFT)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT)/libft.a $(FRAMEWORK) $(MLX)/libmlx42.a -o $@

$(BONUS) : $(OBJB)
	$(CC) $(FLAGS) $(OBJB) $(LIBFT)/libft.a $(FRAMEWORK) $(MLX)/libmlx42.a -o $@

%_bonus.o : %_bonus.c $(INCLUDESB) $(MLX)/libmlx42.a $(LIBFT)/libft.a
	$(CC) $(FLAGS) -c $< -o $@

%.o : %.c $(INCLUDES) $(NWMLX) $(LIBFT)/libft.a
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@make -C $(LIBFT) $@
	@rm -f $(OBJ)
	@rm -f $(OBJB)

fclean : clean
	@make -C $(LIBFT) $@
	@rm -f $(NAME)
	@rm -f $(BONUS)

re : fclean all

.PHONY : clean

# LINUX= -lX11 -lXext -lXrandr

# libf :
# 	make -C $(LIBFT_LINUX)

# $(NAME) : $(OBJ)
# 	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LINUX)/libft.a  $(MLX) $(LINUX) -o $@