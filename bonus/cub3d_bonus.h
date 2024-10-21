/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:04:58 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/21 11:39:37 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define AOV 60
# define PIXELS 60
# define SPEED 15
# define VIEW_SPEED 10 * (M_PI / 180);

typedef struct s_cub
{
    char	*file;
	size_t  len;
	size_t  len_h;
    char	*file2;
    char	*copy;    
    char	*tmp;
	char	*map;
	char	**map1;
	int 	count_player;
}   t_cub;

typedef struct s_texture
{
	char 	*NO;
	char 	*SO;
	char 	*WE;
	char 	*EA;
	int		F[3];
	int		F_color;
	int		C[3];
	int		C_color;
	char	**map;
} t_texture;

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
	int			rds;
	float		rays;
	float		rays_inc;
	float		move_inc;
	char		ply_char;
} t_ply;

typedef struct s_ray
{
	float	ds;
	float	dx;
	float	dy;
	char	hv;
	int		d;
} t_ray;

typedef struct s_ms
{
	int		prevx;
	int		prevy;
	int		curx;
	int		cury;
	float	sensitivity;
}t_ms;

typedef struct s_exec
{
	mlx_t		*mlx;
	mlx_image_t	*wind_image;
	t_info		info;
	t_ply		ply;
	t_texture	text;
	t_cub		cub;
	mlx_image_t	*image;
	mlx_image_t *we;
    mlx_image_t *no;
    mlx_image_t *so;
    mlx_image_t *ea;
    mlx_image_t *d;
	mlx_image_t *wp;
	t_ms		ms;
	char		**av;
	int			i;
	char 		dopen;
}	t_exec;

void	draw_the_player(t_exec *exec, int var, int new_y);

int		ft_check_walls(t_exec *exec, int ind);
int		read_file(char **av, t_cub *cub, t_texture *texture);
int     init_info_struct(t_info *info, t_cub *cub, t_texture *text);
int		init_structs(void *ptr, char **av);
int		creat_and_start_awindow(t_exec *exec);
int		draw_the_floor(t_exec *exec, unsigned int y,  unsigned int x, int var);
int		draw_the_walls(t_exec *exec, unsigned int y,  unsigned int x, int var);
void	set_player_info(t_exec *exec);
void	draw_map(t_exec *exec, int var, int new_y);
void	catch_moves(mlx_key_data_t key, void *p);
void	move_left(t_exec *exec, char ind);
void    move_up(t_exec *exec);
void	move_right(t_exec *exec, char ind);
void	move_down(t_exec *exec);
void	clean_and_exit(void *ptr);

float	degree_to_rad(float deg);
float	rad_to_degree(float rad);
void	ray_casting(t_exec *exec);
void	fill_ray_information(t_exec *exec, t_ray *ray, float angle);
void	it_is_left_or_right(float angle, char *value);
void	fix_current_angle(float *angle);
float	ft_abs(float nm);
void	it_is_up_or_down(float angle, char *value);
void	find_vertical_inter(float angle, t_exec *exec, t_ray *ray, char b);
void	find_horizontal_inter(float angle,t_exec *exec, t_ray *ray, char b);
float	fixing_fichbowl(float ds, float angle, t_exec *exec);
void	draw_the_walls22(int rx, t_exec *exec, float angle, t_ray *ray);
void	fix_current_angle(float *angle);
int		one_of_these(char c);

/*bonus part to remove from this mandatory */
void    draw_mini_map(t_exec *exec);
float	get_persent(float value, float new);
void	mouse_fun(void *ptr);

float	ft_abs(float nm);

#endif
