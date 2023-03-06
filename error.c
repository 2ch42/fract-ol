#include <unistd.h>

void	error_handler(int num)
{
	if (num == 0)
	{
		write(1, "Wrong Input. Try again.\n", 25);
		write(1, "Type ./fract-ol Mandelbrot\n", 28);
		write(1, "or ./fract-ol Julia\n", 21);
	}
	if (num == 1)
	{
		write(1, "Wrong Input. Try again.\n", 25);
		write(1, "Type ./", 10);//should be written.
		write(1, "", 2);//should be written.
	}
}
