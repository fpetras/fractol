/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 07:19:00 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/08 11:35:48 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandelbrot2(t_fract *t, t_complex c)
{
	int		i;
	int		max;
	double	l;

	i = 0;
	max = t->iteration;
	c.c_r = (t->coord.x - WIDTH / 2) / t->zoom_c.x + t->translation.x;
	c.c_i = (t->coord.y - HEIGHT / 2) / t->zoom_c.y + t->translation.y;
	c.z_r = 0;
	c.z_i = 0;
	while ((c.z_r * c.z_r + c.z_i * c.z_i) < 4 && i < max)
	{
		c.tmp_r = c.z_r;
		c.tmp_i = c.z_i;
		c.z_r = c.tmp_r * c.tmp_r - c.tmp_i * c.tmp_i + c.c_r;
		c.z_i = 2 * c.tmp_r * c.tmp_i + c.c_i;
		i++;
	}
	l = ((double)i / max) * t->color_lvl;
	t->image[t->coord.y * WIDTH + t->coord.x] = (i < max) ? ft_color(l) : 0;
	return (0);
}

void		*ft_mandelbrot(void *f)
{
	t_fract		*t;
	t_complex	c;

	t = (t_fract*)f;
	t->zoom_c.x = 0.3 * t->zoom * WIDTH;
	t->zoom_c.y = 0.3 * t->zoom * HEIGHT;
	t->translation.x -= 0.5;
	t->coord.y = t->tx;
	while (t->coord.y < t->ty)
	{
		t->coord.x = 0;
		while (t->coord.x < WIDTH)
		{
			ft_mandelbrot2(t, c);
			t->coord.x++;
		}
		t->coord.y++;
	}
	return (NULL);
}
