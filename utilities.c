/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 07:15:25 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/07 08:13:43 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color(double l)
{
	return (R(l, 31) + G(l, 127) + B(l, 255));
}

int		ft_exit(t_fract *f)
{
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_image(f->mlx, f->img);
	exit(0);
	return (0);
}
