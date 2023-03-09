#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	img_width;
	int	img_height;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef struct s_numset
{
	double	x;
	double	y;
	double	tmp_x;
	double	tmp_y;
	double	a;
	double	b;
}	t_numset;

int	conv_real(double real_val);
int	key_hook(int keycode, t_vars *vars);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
void	error_handler();
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	my_color(int count);
int	mandel_get_count(t_numset *m);
int	exit_hook();
void	mandelbrot(t_data *img);
void	julia(t_data *img, int val1, int va12);

#endif
