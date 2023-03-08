#include <unistd.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>

static int	conv_ab(double real_val)
{
	return (400 + real_val * 200);
}

void	mandelbrot(t_data *img)
{
	t_numset mandel;

	mandel.b = -2;
	while (mandel.b < 2)
	{
		mandel.a = -2;
		while (mandel.a < 2)
		{
			mandel.x = 0;
			mandel.y = 0;
			my_mlx_pixel_put(img, conv_ab(mandel.a), conv_ab(mandel.b), my_color(mandel_get_count(&mandel)));
			mandel.a = mandel.a + 0.005;
		}
		mandel.b = mandel.b + 0.005;
	}
}

int main(int argc, char *argv[])
{
	
	t_vars	vars;
	t_data	image;
	
	if (argc != 2)
	{
		error_handler(0);
		exit(0);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", 10) != 0 && ft_strncmp(argv[1], "Julia", 5) != 0)
	{
		error_handler(0);
		exit(0);
	}
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "fract-ol");
	image.img = mlx_new_image(vars.mlx, 800, 800);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		mandelbrot(&image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	/*
	else if (argv[1] == "Julia")
		julia();
	*/
	mlx_key_hook(vars.win, key_hook, &vars); // esc key press event
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx);
	return (0);
}
