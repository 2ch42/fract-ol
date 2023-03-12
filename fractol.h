#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	img_width;
	int	img_height;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_vars;

typedef struct s_numset
{
	double	x;
	double	y;
	double	tmp_x;
	double	tmp_y;
	double	jul_x;
	double	jul_y;
	double	a;
	double	b;
}	t_numset;

double	to_real(double coor);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	error_handler();
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		my_color(int count);
int		check_conver(double x, double y);
int		exit_hook();
void	mandelbrot(t_vars *img);
void	julia(t_vars *img, int val1, int va12);

#endif
