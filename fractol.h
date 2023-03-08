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

int	key_hook(int keycode, t_vars *vars);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	error_handler(int num);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	my_color(int count);
int	mandel_get_count(t_numset *m);
int	exit_hook();

#endif
