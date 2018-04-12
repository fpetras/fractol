/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:32:33 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/12 09:03:57 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int button, int x, int y, t_fract *f)
{
	if (button == LEFT_CLICK && y >= 0)
	{
		f->press = 1;
		f->move.click_x = x;
		f->move.click_y = y;
	}
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		ft_mouse_zoom(button, x, y, f);
	return (0);
}

int		ft_mouse_release(int button, int x, int y, t_fract *f)
{
	(void)x;
	(void)y;
	if (button == 1)
		f->press = 0;
	return (0);
}

int		ft_mouse_move(int x, int y, t_fract *f)
{
	if (f->press == 1)
	{
		f->move.x = (x - f->move.click_x);
		f->move.y = (y - f->move.click_y);
		f->translation.x -= (f->move.x / f->zoom) / 225;
		f->translation.y -= (f->move.y / f->zoom) / 225;
		ft_fractals(f);
		f->move.click_x = x;
		f->move.click_y = y;
	}
	if (f->lock == 0 && (f->fractal == JULIA || f->fractal == WEB))
	{
		f->c_r = (x - WIDTH / 2) * 0.0035;
		f->c_i = (y - HEIGHT / 2) * 0.0035;
		ft_fractals(f);
	}
	return (0);
}
