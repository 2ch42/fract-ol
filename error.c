#include <unistd.h>

void	error_handler()
{
	write(1, "Wrong Input. Try again.\n", 25);
	write(1, "Type ./fract-ol Mandelbrot\n", 28);
	write(1, "or ./fract-ol Julia [val1] [val2]\n", 35);
}
