/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:34:37 by anqabbal          #+#    #+#             */
/*   Updated: 2024/09/19 17:29:09 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# ifndef PI
# define PI 3.14
# endif

#define PIXELS 30

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

typedef struct s_exec
{
	t_mlx	mlx;
	t_info	inf;
	char	**av;

}	t_exec;

/*PART 2*/
char	**cub_get_map(t_info *inf, int i);
double	degree_to_rad(double deg);
void	to_free(char **av);
int		file_len(t_info *info);

#endif




