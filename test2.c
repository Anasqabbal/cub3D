#include "cub3d.h"

void draw_element(int x, int y, char c, t_mlx *mlx)
{
    t_img img;

    if (c == '0')
        img.color = 0xFFFFFF;
    else if (c == '1')
        img.color = 0xbbbbbb;
    img.xlen = PIXELS; 
    img.ylen = PIXELS;
    img.image = mlx_new_image(mlx->mlx, img.xlen, img.ylen);
    img.image_add = mlx_get_data_addr(img.image, &img.bits_pp, &img.line_, &img.endian);
    set_pixels_to_image(&img);
    mlx_put_image_to_window(mlx->mlx, mlx->mlx_w, img.image, x * PIXELS, y * PIXELS);

}

int main()
{
    int save[2];
    char map[9][20] =
    {"111111111111111111",
     "100000000000000001",
     "10000000P000000001",
     "100000000000000001",
     "100000000000000001",
     "100000000000000001",
     "100000000000000001",
     "111111111111111111",
    };
    int j = -1;
    while (++j < 8)
    {
        printf("%s\n", map[j]);
    }
    double x = 8;
    double y = 2;
     x += cos(60) * 0.1;
     y += sin(60) * 0.1;

    printf("\n\n\n\n\n%d\n", (int)x);
    printf("%d\n", (int)y);
    t_mlx mlx;

    j = -1;
    int i = -1;
    mlx.mlx = mlx_init();
    mlx.mlx_w = mlx_new_window(mlx.mlx, (18 * PIXELS), (8 * PIXELS), "just test");
    while(++j < 8)
    {
        i = -1;
        while(++i < 20)
        {
            if (map[j][i] == '1')
                draw_element(i, j, '1', &mlx);
            else if (map[j][i] == '0')
                draw_element(i, j, '0', &mlx);
            else if (map[j][i] == 'P')
            {
                save[0] = j;
                save[1] = i;
            }
        }
    }
    save[0] = (save[0] * PIXELS) + (PIXELS / 2);
    save[1] = (save[1] * PIXELS) + (PIXELS / 2);

    x = save[1];
    y = save[0];
    int ii = -1;

    printf("player in y %d\n", save[0]);
    printf("player in x %d\n", save[1]);
    int first = PIXELS / 2 + 1;
    while(++ii < 400)
    {
        while(first && --first)
        {
            mlx_pixel_put(mlx.mlx, mlx.mlx_w, (int)x, (int)y, 0x6B6969);
            x += cos(AOV) * 0.1;
            y += cos(AOV) * 0.1;
            printf("player in y %d\n",(int)save[0]);
            printf("player in x %d\n", (int)save[1]);
        }
    }
    mlx_loop(mlx.mlx);

}