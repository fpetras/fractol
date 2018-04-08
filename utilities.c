/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 07:15:25 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/08 11:41:52 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color(double l)
{
	return (R(l, 31) + G(l, 127) + B(l, 255));
}

int		ft_reset(t_fract *f)
{
	f->iteration = ITERATIONS;
	f->zoom = 1;
	f->zoom_lvl = 0;
	f->translation.x = 0;
	f->translation.y = 0;
	f->color_lvl = 5;
	f->lock = 0;
	f->c_r = 0;
	f->c_i = 0;
	ft_fractals(f);
	return (0);
}

int		ft_exit(t_fract *f)
{
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_window(f->mlx, f->win2);
	mlx_destroy_image(f->mlx, f->img);
	exit(0);
	return (0);
}
