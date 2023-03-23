/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:14:00 by changhyl          #+#    #+#             */
/*   Updated: 2023/03/23 21:15:26 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	max;
	double	min;
	double	x;
	double	y;
	double	tmp_x;
	double	tmp_y;
	double	jul_x;
	double	jul_y;
	double	a;
	double	b;
	int		set;
	int		av1;
	int		av2;
}	t_vars;

double	to_real(double coor, t_vars *vars);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	error_handler(void);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		my_color(int count);
int		check_conver(double x, double y);
int		exit_hook(void);
void	mandelbrot(t_vars *img);
void	julia(t_vars *img, int val1, int va12);

#endif
