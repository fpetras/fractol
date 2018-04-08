/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:53:12 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/08 12:12:55 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mlx(t_fract *f)
{
	mlx_key_hook(f->win, ft_keys, f);
	mlx_mouse_hook(f->win, ft_mouse, f);
	mlx_hook(f->win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, ft_mouse_release, f);
	mlx_hook(f->win, MOTION_NOTIFY, POINTER_MOTION_MASK, ft_mouse_move, f);
	mlx_hook(f->win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK, ft_exit, f);
	mlx_loop(f->mlx);
	return (0);
}

static int	ft_controls(t_fract *f)
{
	f->win2 = mlx_new_window(f->mlx, 400, 300, "Controls");
	mlx_string_put(f->mlx, f->win2, 10, 10, 0xFFFFFF, "Keyboard Controls:");
	mlx_string_put(f->mlx, f->win2, 50, 40, 0xCCCCCC, "[1] [2] [3]:     \
	Change Fractal");
	mlx_string_put(f->mlx, f->win2, 50, 70, 0xCCCCCC, "[^] [v] [<] [>]: \
	Move");
	mlx_string_put(f->mlx, f->win2, 50, 100, 0xCCCCCC, "[R]:             \
	Reset");
	mlx_string_put(f->mlx, f->win2, 50, 130, 0xCCCCCC, "[SPACE]:         \
	Lock");
	mlx_string_put(f->mlx, f->win2, 10, 175, 0xFFFFFF, "Mouse Controls:");
	mlx_string_put(f->mlx, f->win2, 50, 205, 0xCCCCCC, "[Wheel]:         \
	Zoom");
	mlx_string_put(f->mlx, f->win2, 50, 235, 0xCCCCCC, "[Click & Drag]:  \
	Move");
	return (0);
}

static int	ft_init(t_fract *f, int fractal)
{
	if ((f->fractal = fractal) == -1)
		return (-1);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->image = (int*)mlx_get_data_addr(f->img, &f->bpp, &f->sl, &f->endian);
	f->iteration = ITERATIONS;
	f->zoom = 1;
	f->zoom_lvl = 0;
	f->translation.x = 0;
	f->translation.y = 0;
	f->lock = 0;
	f->c_r = 0;
	f->c_i = 0;
	return (0);
}

static int	ft_error(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcasecmp(av[1], "mandelbrot") == 0)
			return (MANDELBROT);
		else if (ft_strcasecmp(av[1], "julia") == 0)
			return (JULIA);
		else if (ft_strcasecmp(av[1], "burningship") == 0)
			return (BURNINGSHIP);
		else
			ft_dprintf(2, "usage: %s [mandelbrot | julia | burningship]\n",
				av[0]);
	}
	else
		ft_dprintf(2, "usage: %s [mandelbrot | julia | burningship]\n", av[0]);
	return (-1);
}

int			main(int ac, char **av)
{
	t_fract f;

	if (ft_init(&f, ft_error(ac, av)) == -1)
		return (-1);
	ft_controls(&f);
	ft_fractals(&f);
	ft_mlx(&f);
	return (0);
}
