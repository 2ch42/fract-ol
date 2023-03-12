/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:31 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/12 17:46:46 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

static int	mandel_get_count(t_numset *m)
{
	int		count;
	double	x;
	double	y;
	double	tmp_x;
	double	tmp_y;

	x = 0;
	y = 0;
	count = 0;
	while (count < 100)
	{
		if (check_conver(x, y) == 1)
		{
			tmp_x = x * x - y * y + to_real(m->a);
			tmp_y = 2 * x * y + to_real(m->b);
			x = tmp_x;
			y = tmp_y;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

static int	julia_get_count(t_numset *m)
{
	int	count;

	count = 0;
	m->jul_x = to_real(m->x);
	m->jul_y = to_real(m->y);
	while (count < 100)
	{
		if (check_conver(m->jul_x, m->jul_y) == 1)
		{
			m->tmp_x = m->jul_x * m->jul_x - m->jul_y * m->jul_y + m->a;
			m->tmp_y = 2 * m->jul_x * m->jul_y + m->b;
			m->jul_x = m->tmp_x;
			m->jul_y = m->tmp_y;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

void	mandelbrot(t_vars *vars)
{
	t_numset	mandel;

	mandel.b = 0;
	while (mandel.b < 800)
	{
		mandel.a = 0;
		while (mandel.a < 800)
		{
			my_mlx_pixel_put(vars, mandel.a, mandel.b,
				my_color(mandel_get_count(&mandel)));
			mandel.a += 1;
		}
		mandel.b += 1;
	}
}

void	julia(t_vars *vars, int val1, int val2)
{
	t_numset	julia;

	julia.a = (double)val1 / 1000000;
	julia.b = (double)val2 / 1000000;
	julia.y = 0;
	while (julia.y < 800)
	{
		julia.x = 0;
		while (julia.x < 800)
		{
			my_mlx_pixel_put(vars, julia.x, julia.y,
				my_color(julia_get_count(&julia)));
			julia.x += 1;
		}
		julia.y += 1;
	}
}
