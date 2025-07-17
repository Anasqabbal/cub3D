/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:04:58 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/07 11:45:43 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../libft/libft.h"
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <sys/time.h>

# define AOV 60
# define PIXELS 510
# define TILE_SIZE 510
# define SPEED 100
# define VIEW_SPEED 10

typedef struct s_cub
{
	char	*file;
	size_t	len;
	size_t	len_h;
	char	*file2;
	char	*copy;
	char	*tmp;
	char	*map;
	char	**map1;
	int		count_player;
}	t_cub;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		f_color;
	int		c[3];
	int		c_color;
	char	**map;
}	t_texture;

typedef struct s_info
{
	char			*path;
	unsigned int	map_hei;
	unsigned int	map_wid;
	unsigned int	win_hei;
	unsigned int	win_wid;
	char			**old_map;
	char			**map;
	int				flr_cl;
	int				clg_cl;
}	t_info;

typedef struct s_ply
{
	float		rotangle;
	float		px;
	float		py;
	float		rays;
	float		rays_inc;
	float		move_inc;
	float		old_inc;
	char		ply_char;
}	t_ply;

typedef struct s_ray
{
	float	ds;
	float	dx;
	float	dy;
	char	hv;
	int		d;
	int		wall_height;
	int		x;
	int		o;
}	t_ray;

typedef struct s_ms
{
	int		prevx;
	int		prevy;
	int		curx;
	int		cury;
	float	sensitivity;
}	t_ms;

typedef struct s_mm
{
	int	color;
	int	startx;
	int	endx;
	int	starty;
	int	endy;
	int	px;
	int	py;
	int	i;
	int	j;
	int	new_y;
}	t_mm;

typedef struct s_wp
{
	mlx_image_t		*hld;
	mlx_image_t		**sht;
	mlx_image_t		**rld;
	int				shtnb;
	int				rldnb;
	unsigned char	blt;
}	t_wp;

typedef struct s_exec
{
	mlx_t		*mlx;
	mlx_image_t	*wind_image;
	t_info		info;
	t_ply		ply;
	t_texture	text;
	t_cub		cub;
	t_mm		mm;
	t_ms		ms;
	t_wp		wp;
	t_list		*lst;
	mlx_image_t	*image;
	mlx_image_t	*we;
	mlx_image_t	*no;
	mlx_image_t	*so;
	mlx_image_t	*ea;
	mlx_image_t	*d;
	mlx_image_t	*odll;
	mlx_image_t	*odlr;
	mlx_image_t	*odrl;
	mlx_image_t	*odrr;
	int			imgi;
	int			i;
	int			frst;
}	t_exec;

typedef mlx_image_t	t_mlx;

/*part1*/
int		switch_rgb_hex(int color[3], int a);
int		ft_pixel(int r, int g, int b, int a);
int		get_pixel(unsigned char *pixels, int o);
int		read_file(char **av, t_cub *cub, t_texture *texture);
int		switch_rgb_hex(int color[3], int a);
int		is_invalid(char **map, int i, size_t j);
int		read_textures_colors(t_cub *cub, int fd, t_texture *texture);
int		pars_color_floor_ceiling(char *str, t_texture *texture, int j);
int		parsing_map(t_cub *cub, int len);
int		go_to_check(char *str, t_texture *texture, int i);
int		check_all_is_full(t_texture *texture);
void	draw_the_textures(t_exec *exec, float angle, int *y, t_ray *ray);
t_mlx	*ft_texutre11(t_exec *exec, char *path_texture);

/*part2*/
void	draw_an_image(t_exec *exec, mlx_image_t *img, int startx, int starty);
void	read_images(t_exec *exec, char ind, char *name, int frmnb);
float	adj_dimensions(t_exec *exec, int ind, int fl, int prs);
void	draw_the_player(t_exec *exec, int var, int prs);
int		door_or_wall(t_ray *ray, char c);
int		ft_check_walls(t_exec *exec, int ind);
int		read_file(char **av, t_cub *cub, t_texture *texture);
int		init_info_struct(t_info *info, t_cub *cub, t_texture *text);
int		init_structs(void *ptr, char **av);
int		creat_and_start_awindow(t_exec *exec);
void	set_player_info(t_exec *exec);
void	draw_map(t_exec *exec, int var, int new_y);
void	move_left(t_exec *exec, char ind);
void	move_up(t_exec *exec);
void	move_right(t_exec *exec, char ind);
void	move_down(t_exec *exec);
void	clean_and_exit(void *ptr);
char	the_old_one(t_exec *exec, float oldy, float oldx);
float	degree_to_rad(float deg);
void	ray_casting(t_exec *exec);
void	fill_ray_information(t_exec *exec, t_ray *ray, float angle);
void	it_is_left_or_right(float angle, char *value);
void	fix_current_angle(float *angle);
float	ft_abs(float nm);
void	it_is_up_or_down(float angle, char *value);
void	find_vertical_inter(float angle, t_exec *exec, t_ray *ray, char b);
void	find_horizontal_inter(float angle, t_exec *exec, t_ray *ray, char b);
float	fixing_fichbowl(float ds, float angle, t_exec *exec);
void	draw_the_walls22(int rx, t_exec *exec, float angle, t_ray *ray);
void	fix_current_angle(float *angle);
int		one_of_these(char c);
void	check_what_key_pressed(t_exec *exec, int *flg);
void	draw_mini_map(t_exec *exec);
float	get_persent(float value, float new_v);
void	mouse_fun(void *ptr);
void	fill_xstart_end(t_exec *exec, int *start, int *end, float diff);
void	fill_ystart_end(t_exec *exec, int *start, int *end, float diff);
float	ft_abs(float nm);
void	draw_opened_door(t_exec *exec, int *color, t_ray *ray);
#endif
