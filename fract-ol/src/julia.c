#include "fractol.h"

t_complex	julia_pixel_to_complex(int x, int y, t_fractal *fractal)
{
	t_complex	c;

	c.real = map_range(x, 0, WIDTH, fractal->min.re, fractal->max.re);
	c.imag = map_range(y, 0, HEIGHT, fractal->min.im, fractal->max.im);
	return (c);
}

int	julia_iterate(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;

	z.real = 0.0;
	z.imag = 0.0;
	iter = 0;
	while (iter < max_iter)
	{
		c = complex_add(z, complex_mul(c, c));
		if (complex_magnitude(c) > 2.0)
			break ;
		iter++;
	}
	return (iter);
}

int	julia_color(int iter, int max_iter, t_fractal *fractal)
{
	int	base_color;

	if (iter == max_iter)
		return (0x000000);
	base_color = get_color_scheme(iter, max_iter, fractal->color_scheme);
	if (fractal->color_shift != 0)
		base_color = apply_color_shift(base_color, fractal->color_shift);
	return (base_color);
}

void	julia_set(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = julia_pixel_to_complex(x, y, fractal);
			iter = julia_iterate(c, fractal->max_iter);
			color = julia_color(iter, fractal->max_iter, fractal);
			put_pixel(fractal, x, y, color);
			x++;
		}
		y++;
	}
}
