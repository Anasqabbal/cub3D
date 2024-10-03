#include "cub3d.h"
#include <string.h>

int main()
{
    mlx_t *mlx;

    mlx = mlx_init(1080, 720, "new one", true);

    mlx_image_t *img = mlx_new_image(mlx, 30, 30);
    if (!img)
        printf("error in mlx_new_image\n");

     if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        printf("image to win failure\n");

     mlx_put_pixel(img, 0, 0, 0xFF0000FF);

    // memset(img->pixels, 255, 1080 * 720 * sizeof(int32_t));
    mlx_loop(mlx);
}