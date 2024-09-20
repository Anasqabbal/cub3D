#include <mlx.h>
#include <math.h>

// Function to draw the symmetric points of the circle
void draw_circle_points(void *mlx_ptr, void *win_ptr, int cx, int cy, int x, int y, int color) {
    mlx_pixel_put(mlx_ptr, win_ptr, cx + x, cy + y, color);
    mlx_pixel_put(mlx_ptr, win_ptr, cx - x, cy + y, color);
    mlx_pixel_put(mlx_ptr, win_ptr, cx + x, cy - y, color);
    mlx_pixel_put(mlx_ptr, win_ptr, cx - x, cy - y, color);
    mlx_pixel_put(mlx_ptr, win_ptr, cx + y, cy + x, color);
    mlx_pixel_put(mlx_ptr, win_ptr, cx - y, cy + x, color);
    mlx_pixel_put(mlx_ptr, win_ptr, cx + y, cy - x, color);
    mlx_pixel_put(mlx_ptr, win_ptr, cx - y, cy - x, color);
}

// Midpoint circle drawing algorithm
void draw_circle(void *mlx_ptr, void *win_ptr, int cx, int cy, int radius, int color) {
    int x = 0;
    int y = radius;
    int d = 1 - radius; // Decision parameter

    // Draw the initial points on the axes
    draw_circle_points(mlx_ptr, win_ptr, cx, cy, x, y, color);

    // Iterate over the points until x >= y
    while (x < y)
    {
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        // Draw points for the current (x, y)
        draw_circle_points(mlx_ptr, win_ptr, cx, cy, x, y, color);
    }
}

int main() {
    void *mlx_ptr;
    void *win_ptr;
    int win_width = 800;
    int win_height = 600;

    // Initialize the MiniLibX instance and create a window
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, win_width, win_height, "Circle Drawing");

    // Draw a circle with center (400, 300) and radius 100
    draw_circle(mlx_ptr, win_ptr, 400, 300, 100, 0xFFFFFF);

    // Start the event loop
    mlx_loop(mlx_ptr);

    return 0;
}
