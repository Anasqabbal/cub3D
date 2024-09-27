#include "cub3d.h"

int ft_abs(int nm)
{
    if (nm < 0)
        return (nm *= -1);
    else
        return (nm);
}

void bresenham_line_algo22(int y0, int x0, int y1, int x1, t_mlx mlx)
 {
    int dx;
    int dy;
    int sx ;
    int sy ;
    int err;
    int e2;

    dx = ft_abs(x1 - x0);
    dy = ft_abs(y1 - y0);
    if (x0 < x1)
        sx = 1;
    else 
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx - dy;
    while (1)
    {
        if ((x0 == x1 && y0 == y1))
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
         {
            err += dx;
            y0 += sy; 
        }
        mlx_pixel_put(mlx.mlx, mlx.mlx_w, x0, y0, 0x000000);
    }
}

void set_pixels_to_image(t_img *img, t_exec *exec, int color)
{
	unsigned int	x;
	unsigned int	y;
	char			*image;

	x = 0;
	y = 0;
	(void) exec;
	image = img->image_add;
	while (y < (img->ylen))
	{
		x = 0;
		while(x < (img->xlen))
		{
			if (y != 0 && x != 0)
				*(int *)((image + ((y * img->line_) + (x * (img->bits_pp / 8))))) =  img->color;
			else
				*(int *)((image + ((y * img->line_) + (x * (img->bits_pp / 8))))) =  color;
			x++;
		}
		y++;
	}
}

void draw_element(int x, int y, char c, t_mlx *mlx, int ind)
{
    t_img img;
    int savex;

    savex = x;
    if (c == '0')
        img.color = 0xFFFFFF;
    else if (c == '1')
        img.color = 0xbbbbbb;
    else if (c == 'P')
        img.color = 0x3300B0;
    if (ind == 1)
    {
        img.xlen = PIXELS; 
        img.ylen = PIXELS;
        img.image = mlx_new_image(mlx->mlx, img.xlen, img.ylen);
        img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
        set_pixels_to_image(&img, NULL, img.color);
        mlx_put_image_to_window(mlx->mlx, mlx->mlx_w, img.image, x * PIXELS, y * PIXELS);
    }
    else
    {
        int i;
        int j;
        j = 0;
        while(j < PIXELS)
        {
            i = 0;
            while (++i <= PIXELS)
            {
                mlx_pixel_put(mlx->mlx, mlx->mlx_w, (x * PIXELS) + i, (y * PIXELS) + j , img.color);
                printf("herE i = %d\n", i);
            }
            j++;
        }
    }

}

// double find_hypotenuse(double angle, int opposite)
// {
//     /* know that cos(&) = opp / hypo
//        sin(&) = adj / hypo;
//        tan (&) opp / adj;
//     */

//     h = cos(angle) / opposite
// }

int main()
{
    int height ;
    height = 15;
    int wid = 31;
    int save[2];
    char map[15][98] = 
    {
     "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000001010000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000110000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000P00000000000000000000000000000000000000000000000000000000000000000000010001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
     "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
    };
    int j = -1;
    while (++j < height)
    {
        printf("%s\n", map[j]);
    }
    t_exec exec;
    t_mlx mlx;

    exec.mlx = mlx;
    j = -1;
    int i = -1;
    mlx.mlx = mlx_init();
    mlx.mlx_w = mlx_new_window(mlx.mlx, (wid * PIXELS), (height * PIXELS), "just test");
    while(++j < height)
    {
        i = -1;
        while(++i < wid)
        {
                printf("abyd\n");
            if (map[j][i] == '1')
                draw_element(i, j, '1', &mlx, 1);
            else if (map[j][i] == '0')
                draw_element(i, j, '0', &mlx, 1);
            if (map[j][i] == 'P')
            {
                draw_element(i, j, '0', &mlx, 1);
                save[0] = (j * PIXELS) + (PIXELS / 2);
                save[1] = i * PIXELS + (PIXELS / 2);;
                // save[0] = ((save[0] * PIXELS) + PIXELS / 2);
                // save[1] = (save[1] * PIXELS) + PIXELS / 2;
                mlx_pixel_put(mlx.mlx, mlx.mlx_w, save[1], save[0] + 1, 0x000000);
                mlx_pixel_put(mlx.mlx, mlx.mlx_w, save[1], save[0] - 1, 0x000000);
                mlx_pixel_put(mlx.mlx, mlx.mlx_w, save[1] + 1, save[0], 0x000000);
                mlx_pixel_put(mlx.mlx, mlx.mlx_w, save[1] - 1, save[0], 0x000000);
            }
        }
    }
    int ii = -1;

    double end[2];
    int first = 0;;
    int nexty;
    int nextx;
    int drwx;
    int drwy;
    i = 0;
    double t;
    double rot_angle = 180;
    int count = 0;

    while(i < 60)
    {
        printf("i == %d\n", i);
        end[0] = save[0];
        end[1] = save[1];

        nexty = save[0];
        nextx = save[1];

        
        first = 0;
        t = degree_to_rad((rot_angle - (AOV / 2)) + i);
        printf("t == %f\n", t);
        while(map[(nexty) / PIXELS][(nextx) / PIXELS] != '1')
        {
            if (first == 0 && ++first)
                ii = PIXELS / 2;
            drwy = (int)end[0];
            drwx = (int)end[1];
            end[0] -= (sin(t) * ii); /* y */
            end[1] -= (cos(t) * ii); /* x */
            printf("player in y %d", (int)end[0]);
            printf("player in x %d\n", (int)end[1]);
            ii = 1;
            nexty = ((int)end[0] - 1);
            nextx = ((int)end[1] - 1);
            printf("nexty %d\n",nexty);
            printf("nextx %d\n", nextx);
            if (map[((int)end[0]) / PIXELS][((int)end[1]) / PIXELS] != '1')
            {
                mlx_pixel_put(mlx.mlx, mlx.mlx_w, (int)end[1], (int)end[0], 0x000000);
                // mlx_pixel_put(mlx.mlx, mlx.mlx_w, nextx, nexty, 0xFF0000);
                printf("(%d, %d), %c\n", (nexty - (PIXELS / 2))/ PIXELS, (nextx - (PIXELS / 2))/ PIXELS, map[(nexty - (PIXELS / 2))/ PIXELS][(nextx - (PIXELS / 2)) / PIXELS]);
                // bresenham_line_algo22(drwy, drwx, (int)end[0], (int)end[1], mlx);
            }
        }
        i += 1;
    }
    mlx_loop(mlx.mlx);
}