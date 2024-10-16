#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "./MLX42/include/MLX42/MLX42.h"
#define WIDTH 720
#define HEIGHT 480

typedef void (*mlx_scrollfunc)(float xdelta, float ydelta, void* param);

void my_scrollhook(float xdelta, float ydelta, void* param)
{
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	
	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

void mouse_hook(void *ptr)
{
    mlx_t *mlx;

    mlx = ptr;
    int     x;
    int     y;
     printf("your ptr == %p\n", mlx);
    mlx_set_mouse_pos(mlx, WIDTH / 2, HEIGHT / 2);

    mlx_get_mouse_pos(mlx, &x, &y);
    printf("your pos on x == %d\n and your pos on y == %d\n", x, y);
}

int32_t	main(void)
{
	mlx_t* mlx;


	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
    
    printf("your mlx ptr == %p\n", mlx);
    mlx_loop_hook(mlx, mouse_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}