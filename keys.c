/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:32:19 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/12 09:03:48 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_fn(int keycode, t_fract *f)
{
	if (keycode == FN && f->color_lvl <= MAX_COLOR)
	{
		f->color_lvl += 5;
		ft_fractals(f);
	}
}

static void	ft_up_down_left_right(int keycode, t_fract *f)
{
	if (keycode == LEFT || keycode == RIGHT || keycode == DOWN || keycode == UP)
	{
		keycode == LEFT ? f->translation.x -= 0.1 / f->zoom : 0;
		keycode == RIGHT ? f->translation.x += 0.1 / f->zoom : 0;
		keycode == DOWN ? f->translation.y += 0.1 / f->zoom : 0;
		keycode == UP ? f->translation.y -= 0.1 / f->zoom : 0;
		ft_fractals(f);
	}
	if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D ||
		keycode == KEY_W)
	{
		keycode == KEY_A ? f->translation.x -= 0.1 / f->zoom : 0;
		keycode == KEY_S ? f->translation.y += 0.1 / f->zoom : 0;
		keycode == KEY_D ? f->translation.x += 0.1 / f->zoom : 0;
		keycode == KEY_W ? f->translation.y -= 0.1 / f->zoom : 0;
		ft_fractals(f);
	}
}

static void	ft_digits(int keycode, t_fract *f)
{
	if ((keycode == KEY_1 || keycode == PAD_1) && f->fractal != MANDELBROT)
		f->fractal = MANDELBROT;
	else if ((keycode == KEY_2 || keycode == PAD_2) && f->fractal != JULIA)
		f->fractal = JULIA;
	else if ((keycode == KEY_3 || keycode == PAD_3) &&
			f->fractal != BURNINGSHIP)
		f->fractal = BURNINGSHIP;
	else if ((keycode == KEY_4 || keycode == PAD_4) && f->fractal != TRICORN)
		f->fractal = TRICORN;
	else if ((keycode == KEY_5 || keycode == PAD_5) && f->fractal != WEB)
		f->fractal = WEB;
	else
		return ;
	ft_reset(f);
}

static void	ft_plus_minus(int keycode, t_fract *f)
{
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
}

int			ft_keys(int keycode, t_fract *f)
{
	if (keycode == KEY_R)
		ft_reset(f);
	if (keycode == SPACEBAR && f->zoom_lvl < 42)
		f->lock == 0 ? f->lock++ : f->lock--;
	if (keycode == ESCAPE)
		ft_exit(f);
	ft_plus_minus(keycode, f);
	ft_digits(keycode, f);
	ft_up_down_left_right(keycode, f);
	ft_fn(keycode, f);
	return (0);
}
