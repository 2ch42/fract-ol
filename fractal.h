#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_numset
{
	int	count;
	int	x0;
	int	y0;
	int	a;
	int	b;
}	t_numset;

#endif
