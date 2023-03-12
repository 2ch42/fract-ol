/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:37:06 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/12 17:40:58 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include "fractol.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 2 || (ft_strncmp(argv[1], "Mandelbrot", 10) != 0
			&& ft_strncmp(argv[1], "Julia", 5) != 0)
		|| (ft_strncmp(argv[1], "Julia", 5) == 0 && argc != 4))
	{
		error_handler();
		exit(0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "fract-ol");
	vars.img = mlx_new_image(vars.mlx, 800, 800);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.line_length, &vars.endian);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		mandelbrot(&vars);
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		julia(&vars, ft_atoi(argv[2]), ft_atoi(argv[3]));
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
