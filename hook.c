/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:36:35 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/12 21:28:11 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 4)
	{
		
	}
	else if (mousecode == 5)
	{
		
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
