#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_color(int count)
{
	int	r;
	int	g;
	int	b;

	r = 10 + count;
	g = 63 - 2 * count;
	b = 10 + count;
	return ((r << 16) + (g << 8) + b);
}

static int	check_conver(int x, int y)
{
	if (x * x + y * y > 4)
		return (-1);
	return (1);
}

int	mandel_get_count(t_numset *m)
{
	int	count;

	count = 0;
	while (count < 30)
	{
		if (check_conver(m->x, m->y) == 1)
		{
			m->tmp_x = m->x * m->x + m->y * m->y + m->a;
			m->tmp_y = 2 * m->x * m->y + m->b;
			m->x = m->tmp_x;
			m->y = m->tmp_y;
			count++;
		}
		else
			return (count);
	}
	return (count);
}
