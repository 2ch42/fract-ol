/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:36:04 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/12 17:36:05 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	to_real(double coor)
{
	return (coor / 200 - 2);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_color(int count)
{
	return ((255 << 16 | 255) - count * 15);
}

int	check_conver(double x, double y)
{
	if (x * x + y * y > 4)
		return (-1);
	return (1);
}
