/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:08:19 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/08 09:07:16 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_zoom_out(t_double pos, double move, t_fract *f)
{
	if (f->zoom_lvl < MIN_ZOOM)
		return (0);
	f->iteration -= 1;
	f->zoom /= 1.1;
	f->zoom_lvl = f->iteration - ITERATIONS;
	if (f->lock == 0)
		f->lock = (f->zoom_lvl > 42) ? 1 : 0;
	f->translation.y -= (pos.y / f->zoom) / fabs((move / (WIDTH / 25) - 18));
	f->translation.x -= (pos.x / f->zoom) / fabs((move / (HEIGHT / 25) - 18));
	return (0);
}

static int	ft_zoom_in(t_double pos, double move, t_fract *f)
{
	if (f->zoom_lvl > MAX_ZOOM)
		ft_reset(f);
	f->iteration += 1;
	f->zoom *= 1.1;
	f->zoom_lvl = f->iteration - ITERATIONS;
	if (f->lock == 0)
		f->lock = (f->zoom_lvl > 42) ? 1 : 0;
	f->translation.y += (pos.y / f->zoom) / fabs((move / (WIDTH / 25) - 18));
	f->translation.x += (pos.x / f->zoom) / fabs((move / (HEIGHT / 25) - 18));
	return (0);
}

int			ft_zoom(int button, int x, int y, t_fract *f)
{
	t_double	pos;
	double		translation;

	pos.x = x - WIDTH / 2;
	pos.y = y - HEIGHT / 2;
	translation = sqrt(pos.x * pos.x + pos.y * pos.y);
	pos.x /= translation;
	pos.y /= translation;
	button == 4 ? ft_zoom_in(pos, translation, f) : 0;
	button == 5 ? ft_zoom_out(pos, translation, f) : 0;
	ft_fractals(f);
	return (0);
}
