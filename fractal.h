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
	int	count;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	a;
	double	b;
}	t_numset;

#endif
