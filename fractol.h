/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:45:43 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/07 08:35:27 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

# include <math.h>
# include <mlx.h>
# include <pthread.h>

# define ESCAPE					53
# define KEY_R					15
# define SPACEBAR				49
# define LEFT					123
# define RIGHT					124
# define DOWN					125
# define UP						126

# define BUTTON_RELEASE			5
# define MOTION_NOTIFY			6
# define DESTROY_NOTIFY			17
# define BUTTON_RELEASE_MASK	1L<<3
# define POINTER_MOTION_MASK	1L<<6
# define STRUCTURE_NOTIFY_MASK	1L<<17

# define MANDELBROT				1
# define JULIA					2
# define BURNINGSHIP			3

# define WIDTH					750
# define HEIGHT					750

# define ITERATIONS				100
# define THREADS				32

# define R(L, R) ((int)(L * R) << 16)
# define G(L, G) ((int)(L * G) << 8)
# define B(L, B) ((int)(L * B))

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_double
{
	double		x;
	double		y;
}				t_double;

typedef struct	s_complex
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp_r;
	double		tmp_i;
}				t_complex;

typedef struct	s_fractol
{
	int			fractal;

	void		*mlx;
	void		*win;
//	void		*win2;

	void		*img;
	int			*image;
	int			bpp;
	int			sl;
	int			endian;

	int			iteration;
	int			tx;
	int			ty;
	int			zoom;
	double		zoom_lvl;
	t_point		coord;
	t_double	move;
	t_double	zoomc;
}				t_fract;

int				ft_fractals(t_fract *f);
void			*ft_mandelbrot(void *f);
int				ft_keys(int keycode, t_fract *f);
int				ft_mouse_press(int button, int x, int y, t_fract *f);
int				ft_mouse_release(int button, int x, int y, t_fract *f);
int				ft_mouse_move(int x, int y, t_fract *f);
int				ft_color(double l);
int				ft_exit(t_fract *f);
int				ft_strcasecmp(const char *s1, const char *s2);

#endif
