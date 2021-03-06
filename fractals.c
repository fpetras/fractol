/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 08:00:08 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/13 10:57:52 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractals(t_fract *f)
{
	int			i;
	t_fract		t[THREADS];
	pthread_t	thr[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		t[i] = *f;
		t[i].tx = i * (WIDTH / THREADS);
		t[i].ty = (i + 1) * (HEIGHT / THREADS);
		if (f->fractal == MANDELBROT)
			pthread_create(&thr[i], NULL, ft_mandelbrot, &t[i]);
		else if (f->fractal == JULIA)
			pthread_create(&thr[i], NULL, ft_julia, &t[i]);
		else if (f->fractal == BURNINGSHIP)
			pthread_create(&thr[i], NULL, ft_burningship, &t[i]);
		else if (f->fractal == TRICORN)
			pthread_create(&thr[i], NULL, ft_mandelbar, &t[i]);
		else if (f->fractal == WEB)
			pthread_create(&thr[i], NULL, ft_web, &t[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(thr[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
