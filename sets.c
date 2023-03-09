#include "mlx/mlx.h"
#include "fractol.h"

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
			my_mlx_pixel_put(img, conv_real(mandel.a), conv_real(mandel.b), my_color(mandel_get_count(&mandel)));
			mandel.a += 0.005;
		}
		mandel.b += 0.005;
	}
}

void	julia(t_data *img, int val1, int val2)
{
	t_numset	julia;

	julia.a = val1 / 1000000;
	julia.b = val2 / 1000000;

	julia.y = -2;
	while (julia.y < 2)
	{
		julia.x = -2;
		while (julia.x < 2)
		{
			my_mlx_pixel_put(img, conv_real(julia.x), conv_real(julia.y), my_color(mandel_get_count(&julia)));
			julia.x += 0.005;
		}
		julia.y += 0.005;
	}
}
