/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:34:37 by anqabbal          #+#    #+#             */
/*   Updated: 2024/11/07 11:42:07 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define AOV 60
# define PIXELS 510
# define SPEED 100
# define VIEW_SPEED 10

typedef mlx_image_t	t_img;

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
	int		wall_height;
	int		x;
	int		o;
}	t_ray;

typedef struct s_tex
{
	void	*image;
	void	*flr;
	void	*wall;
	t_ply	ply;
}	t_tex;

typedef struct s_exec
{
	mlx_t		*mlx;
	mlx_image_t	*wind_image;
	t_info		info;
	t_ply		ply;
	t_texture	text;
	t_cub		cub;
	char		**av;
	int			i;
	mlx_image_t	*image;
	mlx_image_t	*we;
	mlx_image_t	*no;
	mlx_image_t	*so;
	mlx_image_t	*ea;
	mlx_image_t	*d;
}	t_exec;

int		read_file(char **av, t_cub *cub, t_texture *texture);
int		read_textures_colors(t_cub *cub, int fd, t_texture *texture);
int		parsing_map(t_cub *cub, int len);
int		pars_color_floor_ceiling(char *str, t_texture *texture, int j);
int		is_invalid(char **map, int i, size_t j);
int		switch_rgb_hex(int color[3], int a);
void	draw_the_textures(t_exec *exec, float angle, int *y, t_ray *ray);
int		get_pixel(unsigned char *pixels, int o);
t_img	*ft_texutre11(t_exec *exec, char *path_texture);

int		ft_check_walls(t_exec *exec, int ind);
int		init_info_struct(t_info *info, t_cub *cub, t_texture *text);
int		init_structs(void *ptr, char **av);
int		creat_and_start_awindow(t_exec *exec);
void	set_player_info(t_exec *exec);
void	catch_moves(void *p);
void	move_left(t_exec *exec, char ind);
void	move_up(t_exec *exec);
void	move_right(t_exec *exec, char ind);
void	move_down(t_exec *exec);
void	clean_and_exit(void *ptr);
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
float	ft_abs(float nm);
#endif