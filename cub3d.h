/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:34:37 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/24 17:43:06 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
// # include <mlx.h>
# include "./minilibx-linux/mlx.h"

# define AOV 60
# define PIXELS 60
# define SPEED 10

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_w;
	void	*mlx_img_add;
	unsigned int	win_hei;
	unsigned int	win_wid;
}	t_mlx;

typedef struct s_info
{
	char		*path;
	unsigned int hei;
	unsigned int wid;
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
	void	*img;
	int		turn;
	double		rotangle;
	int		px;
	int		py;
	int		rds;
	int		endlx;
	int		endrx;
	int		enduy;
	int		enddy;
} t_ply;

typedef struct s_tex
{
	void	*wall;
	t_ply	ply;
	t_ply	flr;

} t_tex;

typedef struct s_ray
{
	int	x;
	int	y;
	int	len;
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
	t_mlx	mlx;
	t_info	inf;
	t_img	img;
	t_tex	tex;
	t_ray	line;
	char	**av;

}	t_exec;


/*PART 2*/
void	ft_draw_rays(t_exec *exec);
char	**cub_get_map(t_info *inf, int i);
double	degree_to_rad(double deg);
void	to_free_cub(char **av);
int		file_len(t_info *info);
int		creat_and_start_awindow(t_mlx *mlx);
void	set_pixels_to_image(t_img *img);
int		draw_the_floor(t_exec *exec);
int		draw_the_walls(t_exec *exec);
int		draw_the_player(t_exec *exec);
int     init_info_struct(t_info *inf, char **av);
int		init_structs(void *ptr, int ind, char **av);
int		init_mlx_struct(t_exec *exec);
int		catch_moves(int key, void *p);
int		ft_move_player(t_exec *exec);
void	draw_circle(t_exec *exec, t_cir *cir);
int		check_walls(int ind, int y, int x, t_exec *exec);
int 	ft_dda_algo(t_exec *exec, double endy, double endx);
double	rad_to_degree(double rad);

#endif




