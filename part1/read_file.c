/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:35:55 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/10/12 16:19:21 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int switch_RGB_hex(int color[3])
{
	return ((color[0] << 16 | color[1] << 8) | color[2]);
}

int pars_color_floor_ceiling(char *str, t_texture *texture, int j)
{
	int i;
	int k;
	char **new;
	char *trim;

	i = j + 1;
	trim = ft_strtrim(&str[i],"\n");
	trim = ft_strtrim(trim," ");

	i = 0;
	while (trim[i] != '\0')
	{
		if (!ft_isdigit(trim[i]) && trim[i] != ',' && trim[i] != ' ') {
			printf("Error\nadd just numbers separetly with `,` in F and C\n");
			return 1;
		}
		i++;
	}
	i = 0;
	if (trim[i] == ',')
		return (printf("Error\nError:`,` in the first \n"), 1);
	int sq = 0;
	while (trim[i] != '\0')
	{
		if (trim[i] == ',')
			sq++;
		if (trim[i] == ' ')
		{
			i++;
			continue;
		}
		if ((trim[i] == ',' && trim[i + 1] == ','))
			return (printf("Error: Invalid character '%c' at position %d\n", trim[i],i), 1);
		if (trim[i] == ',' && (trim[i + 1] == '\n' || trim[i + 1] == '\0'))
			return (printf("Errror\nYou have a `,` in the last in F or C\n"), 1);
		i++;
	}
	if (sq > 2)
		return (printf("Error\nthe number of parametr in F or C is not correct\n"), 1);
	new = ft_split(trim, ',');
	k = 0;
	while (new[k])
	{
		int o = 0;
		int count = 0;
		trim = ft_strtrim(new[k]," ");
		while (trim[o])
		{
			if (trim[o] == ' ')
				return (printf("error\nthis number {%s} is not correct \n", trim), 1);
			if (ft_isdigit(trim[o]))
				count ++;
			o++;
		}
		if (count > 3)
			return (printf("error\nthis number {%s} is not correct \n",trim), 1);
		k++;
	}
	if (str[j] == 'F')
	{
		i = 0;
		while(new[i])
		{
			texture->F[i] = ft_atoi(new[i]);
			if (texture->F[i] > 255)
				return (printf("error\nthis number {%d} > 255\n",texture->F[i]), 1);
			i++;
		}
		// texture->F_color = switch_RGB_hex(texture->F);
		// printf("Hexadecimal: 0x%X\n", texture->F_color);
	}
	if (str[j] == 'C')
	{
		i = 0;
		while(new[i])
		{
			texture->C[i] = ft_atoi(new[i]);
			if ( texture->C[i] > 255)
				return (printf("error\nthis number {%d} > 255\n",texture->C[i]), 1);
			i++;
		}
	}
	return 0;
}

int go_to_check(char *str, t_texture *texture, int i)
{
	while (str[i] == ' ')
		i++;
	int j = i;
	if (((str[i] == 'F') || (str[i] == 'C'))
		&& (str[i + 1] == ' '))
	{
		if (pars_color_floor_ceiling(str, texture, i))
			return 1;
	}
	else if (((str[i] == 'N' && str[i + 1] == 'O')
			||(str[i] == 'S' && str[i + 1] == 'O')
			||(str[i] == 'W' && str[i + 1] == 'E')
			||(str[i] == 'E' && str[i + 1] == 'A'))
			&& (str[i + 2] == ' '))
	{
		i += 2;
		while(str[i] == ' ')
			i++;
		if (str[j] == 'N' && str[j + 1] == 'O')
			texture->NO = ft_strdup1(&str[i]);
		if (str[j] == 'S' && str[j + 1] == 'O')
			texture->SO = ft_strdup1(&str[i]);
		if (str[j] == 'W' && str[j + 1] == 'E')
			texture->WE = ft_strdup1(&str[i]);
		if (str[j] == 'E' && str[j + 1] == 'A')
			texture->EA = ft_strdup1(&str[i]);
	}
	else 
		return (printf("error\nerror in direction -> %s", str), 1);
	return 0;
}

void init_variables_direction(t_texture *texture)
{
	/*initialaze avariable*/
	texture->EA = NULL;
	texture->NO = NULL;
	texture->SO = NULL;
	texture->WE = NULL;
	texture->map = NULL;
	texture->F[0] = -1;
	texture->F[1] = -1;
	texture->F[2] = -1;
	texture->C[0] = -1;
	texture->C[1] = -1;
	texture->C[2] = -1;
}
int check_all_is_full(t_texture *texture)
{
	/*check all variable in struct is full*/
	if (texture->EA != NULL &&  texture->NO != NULL
		&& texture->SO != NULL &&  texture->WE != NULL
		&& texture->F[0] >= 0 && texture->F[1] >= 0
		&& texture->F[2] >= 0 && texture->C[0] >= 0
		&& texture->C[1] >= 0 && texture->C[2] >= 0)
		return 1;
	return 0;
}
int check_valid_map(char **map, int i, int count)
{
	int j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			/*count map is have this caracters '1' '0' ' ' 'S' 'W' 'N' 'E' */
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != ' ' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
				return (printf("Error\ninvalid caracter '%c' in map\n", map[i][j]),1);
			/*count player*/
			if (map[i][j] == 'S'
				|| map[i][j] == 'N'
				|| map[i][j] == 'W'
				|| map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	/*check player*/
	if (count != 1)
		return (printf("you have multiple player or you don't have any player\n"), 1);
	return (0);
}
int is_invalid(char **map, int i, size_t j)
{
    return (
        ((i == 0 || j == 0) && map[i][j] == '0') ||
        (map[i][j + 1] == ' ' || map[i][j - 1] == ' '|| map[i][j + 1] == '\0') ||
        ((map[i - 1][j] == ' ' || map[i - 1][j] == '\0')) ||
        (map[i + 1] == NULL || (map[i + 1][j] == ' ' || map[i + 1][j] == '\0'))
    );
}
int parsing_map(t_cub *cub, int len)
{
	/* split '\n' in map to change it to 2D array */
	cub->map1 = ft_split1(cub->map, '\n',len);
	/*check valid caracter in map*/
	if (check_valid_map(cub->map1, 0, 0))
		return (1);
	int i = 0;
	size_t j = 0;
	int p = 0;
	/*now check  is avalid map or not*/
	while (cub->map1[i])
	{
		j = 0;
		/*skip just ' '*/
		while (cub->map1[i][j] == ' ')
			j++;
		if (cub->map1[i][j] == '\0')
		{
			int k = i - 1;
			while(cub->map1[k][j] == ' ')
				j++;
			while (cub->map1[k][j])
			{
				if (cub->map1[k][j] != '1')
					return (printf("NOT VALID ==> %s\n", cub->map1[k]),1);
				j++;
			}
			i++;
			p = i;
			continue;
		}
		while (cub->map1[i][j])
		{
			if ((cub->map1[i][j] == '0' 
				|| cub->map1[i][j] == 'N' 
				|| cub->map1[i][j] == 'W' 
				|| cub->map1[i][j] == 'E' 
				|| cub->map1[i][j] == 'S')
				&& is_invalid(cub->map1, i ,j))
				return (printf("NOT VALID ==> %s\n", cub->map1[i]),1);
			j++;
		}
		i++;
	}
	cub->len_h = i;
	printf("%d\n\n\n", i);
	return 0;	
}
int read_textures_colors(t_cub *cub, int fd ,t_texture *texture)
{
    int i;
    
    while(cub->file != NULL)
	{   
		i = 0;
		char *trim = ft_strtrim(cub->file, " ");
		while(trim[i])
			i++;
		if ((i > 0) && trim[i - 1] != '\n')
			return (close(fd), write(2, "error\nerror new line\n", 21) ,1);
		if (i == 1 && trim[i - 1] == '\n')
		{
			cub->file = get_next_line(fd);
			continue;
		}
		if (check_all_is_full(texture))
			break;
		if (go_to_check(cub->file, texture, 0))
				return (close(fd),1);
		cub->file = get_next_line(fd);
	}
    return 0;
}
int read_file(char **av, t_cub *cub, t_texture *texture)
{
	int fd;
	int i;

	init_variables_direction(texture);

	fd = open(av[1], O_RDWR);
	if (fd < 0)
		return (1);
	cub->file = get_next_line(fd);
	if (!(cub->file))
		return (write(2, "error\nempty file\n", 17) ,1);
	/*read just a textures and color*/
    if (read_textures_colors(cub, fd,texture))
        return (1);
	
	/*if all variable (texture and color is full) go to read map now and join in this variable cub->map*/
	cub->len = 0;
	if (cub->file)
	{
		cub->map = NULL;
		while(cub->file != NULL)
		{
			size_t j = ft_strlen(cub->file);// for check largest line for allocat in split1
			i = 0;
			while(cub->file[i])
				i++;
			// if ((i > 0) && cub->file[i - 1] != '\n')
			// 	return (close(fd), write(2, "error\nadd a new line in the last line in map\n", 45) ,1);
			if (i == 1 && cub->file[i - 1] == '\n')
				return (close(fd), write(2, "error\nerror in map", 18) ,1);
			if (j > cub->len)
				cub->len = j;
			cub->map = ft_strjoin1(cub->map, cub->file);
			cub->file = get_next_line(fd);
		}
	}
	else
		return (printf("error\nput your map\n"), 1);
	close(fd);
	/*after read map go to parsing this map*/
	if (parsing_map(cub, cub->len))
		return (1);
	else
		texture->map = cub->map1;
	return (0);
}