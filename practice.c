#include <unistd.h>
#include <stdlib.h>
#include "mlx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot()
{
	t_numset mandel;

	mandel->x0 = 0;
	mandel->y0 = 0;
	mandel->count = 0;

	while (mandel->x0 < 1920)
	{
		
	}

}

void	error_handler(int num)
{
	if (num == 0)
	{
		write(1, "Wrong Input. Try again.\n", 25);
		write(1, "Type ./fract-ol Mandelbrot\n", 28);
		write(1, "or ./fract-ol Julia\n", 21);
	}
	if (num == 1)
	{
		write(1, "Wrong Input. Try again.\n", 25);
		write(1, "", );//should be written.
		write(1. "", );//should be written.
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error_handler(0);
		exit(0);
	}
	else if (argv[1] != "Mandelbrot" || argv[1] != "Julia")
	{
		error_handler(0);
		exit(0);
	}
	if (argv[1] == "Mandelbrot")
		mandelbrot();
	else if (argv[1] == "Julia")
		julia();
	return (0);
}
