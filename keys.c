/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:32:19 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/08 09:22:20 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_keys(int keycode, t_fract *f)
{
	if (keycode == ESCAPE)
		ft_exit(f);
	if (keycode == KEY_R)
		ft_reset(f);
	if (keycode == SPACEBAR && f->zoom_lvl < 42)
		f->lock == 0 ? f->lock++ : f->lock--;
	if (keycode == LEFT || keycode == RIGHT || keycode == DOWN || keycode == UP)
	{
		keycode == LEFT ? f->move.x -= 0.05 / f->zoom : 0;
		keycode == RIGHT ? f->move.x += 0.05 / f->zoom : 0;
		keycode == DOWN ? f->move.y += 0.05 / f->zoom : 0;
		keycode == UP ? f->move.y -= 0.05 / f->zoom : 0;
		ft_fractals(f);
	}
	return (0);
}
