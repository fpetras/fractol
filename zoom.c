/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:08:19 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/09 09:33:22 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_out(t_fract *f)
{
	if (f->zoom_lvl < MIN_ZOOM)
		return ;
	f->iteration -= 1;
	f->zoom /= 1.1;
	f->zoom_lvl = f->iteration - ITERATIONS;
	if (f->lock == 0)
		f->lock = (f->zoom_lvl > 42) ? 1 : 0;
}

void	ft_zoom_in(t_fract *f)
{
	if (f->zoom_lvl > MAX_ZOOM)
		ft_reset(f);
	f->iteration += 1;
	f->zoom *= 1.1;
	f->zoom_lvl = f->iteration - ITERATIONS;
	if (f->lock == 0)
		f->lock = (f->zoom_lvl > 42) ? 1 : 0;
}

void	ft_mouse_zoom(int button, int x, int y, t_fract *f)
{
	t_double	pos;
	double		tl;

	pos.x = x - WIDTH / 2;
	pos.y = y - HEIGHT / 2;
	tl = sqrt(pos.x * pos.x + pos.y * pos.y);
	pos.x /= tl;
	pos.y /= tl;
	if (button == SCROLL_UP && f->zoom_lvl < MAX_ZOOM)
	{
		ft_zoom_in(f);
		f->translation.x += (pos.x / f->zoom) / fabs((tl / (HEIGHT / 25) - 18));
		f->translation.y += (pos.y / f->zoom) / fabs((tl / (WIDTH / 25) - 18));
	}
	if (button == SCROLL_DOWN && f->zoom_lvl > MIN_ZOOM)
	{
		ft_zoom_out(f);
		f->translation.x -= (pos.x / f->zoom) / fabs((tl / (HEIGHT / 25) - 18));
		f->translation.y -= (pos.y / f->zoom) / fabs((tl / (WIDTH / 25) - 18));
	}
	(f->zoom_lvl >= MAX_ZOOM) ? ft_reset(f) : 0;
	ft_fractals(f);
}
