/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:34:44 by changhyl          #+#    #+#             */
/*   Updated: 2023/04/29 20:36:40 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	error_handler(void)
{
	write(1, "Wrong Input. Try again.\n", 25);
	write(1, "Type ./fract-ol Mandelbrot\n", 28);
	write(1, "or ./fract-ol Julia [val1] [val2]\n", 35);
	exit(0);
}
