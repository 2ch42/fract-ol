#include <unistd.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>

void	mandelbrot(t_data *img)
{
	t_numset mandel;

	mandel.b = -400;
	while (mandel.b < 400)
	{
		mandel.a = -500;
		while (mandel.a < 500)
		{
			mandel.x = 0;
			mandel.y = 0;
			my_mlx_pixel_put(img, mandel.a + 500, mandel.b + 400, my_color(mandel_get_count(&mandel)));
			mandel.a++;
		}
		mandel.b++;
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
	vars.win = mlx_new_window(vars.mlx, 1000, 800, "fract-ol");
	image.img = mlx_new_image(vars.mlx, 1000, 800);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		mandelbrot(&image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	/*
	else if (argv[1] == "Julia")
		julia();
	*/
	mlx_loop(vars.mlx);
	return (0);
}
