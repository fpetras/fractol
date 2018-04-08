/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:32:19 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/08 10:03:56 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_keys(int keycode, t_fract *f)
{
	if (keycode == KEY_R)
		ft_reset(f);
	if (keycode == SPACEBAR && f->zoom_lvl < 42)
		f->lock == 0 ? f->lock++ : f->lock--;
	if (keycode == ESCAPE)
		ft_exit(f);
	if (keycode == PLUS || keycode == PAD_ADD)
	{
		ft_zoom_in(f);
		ft_fractals(f);
	}
	if (keycode == MINUS || keycode == PAD_SUB)
	{
		ft_zoom_out(f);
		ft_fractals(f);
	}
	if (keycode == LEFT || keycode == RIGHT || keycode == DOWN || keycode == UP)
	{
		keycode == LEFT ? f->translation.x -= 0.1 / f->zoom : 0;
		keycode == RIGHT ? f->translation.x += 0.1 / f->zoom : 0;
		keycode == DOWN ? f->translation.y += 0.1 / f->zoom : 0;
		keycode == UP ? f->translation.y -= 0.1 / f->zoom : 0;
		ft_fractals(f);
	}
	return (0);
}
