/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 08:52:50 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/10 09:04:29 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_brain2(t_fract *t, t_complex c)
{
	int		i;
	int		max;
	double	l;

	i = 0;
	max = t->iteration;
	c.z_r = (t->coord.x - WIDTH / 2) / t->zoom_c.x + t->translation.x;
	c.z_i = (t->coord.y - HEIGHT / 2) / t->zoom_c.y + t->translation.y;
	while ((c.z_r * c.z_r + c.z_i * c.z_i) < 4 && i < max)
	{
		c.tmp_r = c.z_i;
		c.tmp_i = c.z_r;
		c.z_r = c.tmp_r * c.tmp_r - c.tmp_i * c.tmp_i + c.c_r;
		c.z_i = 4 * c.tmp_r * c.tmp_i + c.c_i;
		i++;
	}
	l = ((double)i / max) * t->color_lvl;
	t->image[t->coord.y * WIDTH + t->coord.x] = (i < max) ? ft_color(l) : 0;
}

void		*ft_brain(void *f)
{
	t_fract		*t;
	t_complex	c;

	t = (t_fract*)f;
	t->zoom_c.x = 0.3 * t->zoom * WIDTH;
	t->zoom_c.y = 0.3 * t->zoom * HEIGHT;
	t->coord.y = t->tx;
	while (t->coord.y < t->ty)
	{
		t->coord.x = 0;
		c.c_r = t->c_r;
		c.c_i = t->c_i;
		while (t->coord.x < WIDTH)
		{
			ft_brain2(t, c);
			t->coord.x++;
		}
		t->coord.y++;
	}
	return (NULL);
}
