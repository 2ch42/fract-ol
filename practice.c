#include <unistd.h>
#include <stdlib.h>
#include "mlx/mlx.h"

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 4)
	{

	}
	else if (mousecode == 5)
	{
		
	}
}
*/

int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int exit_hook()
{
	exit(0);
}

int	prtimage(char *set)
{
	if (set == "Mandelbrot")
	{
		
	}
}

void	error_handler(int num)
{
	if (num == 0)
	{
		write(1, "Wrong Input. Try again.\n", 25);
		write(1, "Type ./fract-ol Mandelbrot\n", 28);
		write(1, "or ./fract-ol Julia\n", 21);
	}

}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error_handler(0);
		exit(0);
	}
	else if (argv[1] != "Mandelbro" || argv[1] != "Julia")
	{
		error_handler(0);
		exit(0);
	}
	prtimage(argv[1]);
	return (0);
}
