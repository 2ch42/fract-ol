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

static int	mandel_get_count(t_vars *vars)
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
			tmp_x = x * x - y * y + to_real(vars->a, vars);
			tmp_y = 2 * x * y + to_real(vars->b, vars);
			x = tmp_x;
			y = tmp_y;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

static int	julia_get_count(t_vars *vars)
{
	int	count;

	count = 0;
	vars->jul_x = to_real(vars->x, vars);
	vars->jul_y = to_real(vars->y, vars);
	while (count < 100)
	{
		if (check_conver(vars->jul_x, vars->jul_y) == 1)
		{
			vars->tmp_x = vars->jul_x * vars->jul_x
				- vars->jul_y * vars->jul_y + vars->a;
			vars->tmp_y = 2 * vars->jul_x * vars->jul_y + vars->b;
			vars->jul_x = vars->tmp_x;
			vars->jul_y = vars->tmp_y;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

void	mandelbrot(t_vars *vars)
{
	vars->b = 0;
	while (vars->b < 800)
	{
		vars->a = 0;
		while (vars->a < 800)
		{
			my_mlx_pixel_put(vars, vars->a, vars->b,
				my_color(mandel_get_count(vars)));
			vars->a += 1;
		}
		vars->b += 1;
	}
}

void	julia(t_vars *vars, int val1, int val2)
{
	vars->a = (double)val1 / 1000000;
	vars->b = (double)val2 / 1000000;
	vars->y = 0;
	while (vars->y < 800)
	{
		vars->x = 0;
		while (vars->x < 800)
		{
			my_mlx_pixel_put(vars, vars->x, vars->y,
				my_color(julia_get_count(vars)));
			vars->x += 1;
		}
		vars->y += 1;
	}
}
