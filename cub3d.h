/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:34:37 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/12 11:47:35 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
// # include <mlx.h>
// # include "./minilibx-linux/mlx.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define AOV 60
# define PIXELS 60
# define SPEED 5
# define VIEW_SPEED 5 * (M_PI / 180);

typedef struct s_info
{
	char		*path;
	unsigned int win_hei;
	unsigned int win_wid;
	char		**map;
	int			flr_cl;
	int			clg_cl;
}	t_info;

typedef struct s_img
{
	void			*image;
	char			*image_add;
	int				bits_pp;
	int				line_;
	int				endian;
	unsigned int	xlen;
	unsigned int	ylen;
	int				color;
}	t_img;

typedef struct s_ply
{
	int			color;
	void		*img;
	int			turn;
	double		rotangle;
	double		px;
	double		py;
	int			rds;
	int			endlx;
	int			endrx;
	int			enduy;
	int			enddy;
	double		rays;
	double		rays_inc;
	double		move_inc;
} t_ply;

typedef struct s_tex
{
	void	*image;
	void	*flr;
	void	*wall;
	t_ply	ply;

} t_tex;

typedef struct s_ray
{
	double	ds;
	double	dx;
	double	dy;
	char	hv;
} t_ray;

typedef struct s_cir
{
	int	x;
	int	y;
	int	cx;
	int cy;
	int rds;
	int to_center;
	int to_fill;
} t_cir;

typedef struct s_exec
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*wind_image;
	t_info		info;
	t_img		img;
	t_tex		tex;
	t_ray		*ray;
	t_ray		ray90;
	char		**av;
}	t_exec;


/*PART 2*/

int ft_check_walls(t_exec *exec, int ind);


int     init_info_struct(t_info *inf, char **av);
int		init_structs(void *ptr, int ind, char **av);
int		file_len(t_info *info);
char	**cub_get_map(t_info *inf, int i);
int		creat_and_start_awindow(t_exec *exec);
int		draw_the_floor(t_exec *exec, unsigned int y,  unsigned int x);
int		draw_the_walls(t_exec *exec, unsigned int y,  unsigned int x);
int		set_player_info(t_exec *exec);
void	draw_map(t_exec *exec);
void	catch_moves(mlx_key_data_t key, void *p);
void	move_left(t_exec *exec, char ind);
void    move_up(t_exec *exec);
void	move_right(t_exec *exec, char ind);
void	move_down(t_exec *exec);
void	ft_clean_and_exit(t_exec *exec);


double	degree_to_rad(double deg);
void	to_free_cub(char **av);
void	set_pixels_to_image(t_exec *exec, int color1,  int color2);
int		ft_move_player(t_exec *exec);
void	draw_circle(t_exec *exec, t_cir *cir);
int 	ft_dda_algo(t_exec *exec, double endy, double endx);
double	rad_to_degree(double rad);
void	bresenham_line_algo2(int y0, int x0, int y1, int x1, t_exec *exec);
int		ray_casting(t_exec *exec);
void	fill_ray_information(t_exec *exec, t_ray *ray, double angle);
void	it_is_left_or_right(double angle, char *value);
void	fix_current_angle(double *angle);
double	ft_abs(double nm);
void	it_is_up_or_down(double angle, char *value);
int		find_vertical_inter(double angle, t_exec *exec, t_ray *ray);
int		find_horizontal_inter(double angle,t_exec *exec, t_ray *ray);
double	fixing_fichbowl(double ds, double angle, t_exec *exec);
void	draw_the_walls22(int rx, t_exec *exec, double angle, t_ray *ray);

double	ft_abs(double nm);

#endif




