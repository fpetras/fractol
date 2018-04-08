/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:45:43 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/08 12:56:22 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define BUTTON_RELEASE			5
# define MOTION_NOTIFY			6
# define DESTROY_NOTIFY			17
# define BUTTON_RELEASE_MASK	1L<<3
# define POINTER_MOTION_MASK	1L<<6
# define STRUCTURE_NOTIFY_MASK	1L<<17

# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13
# define KEY_R					15
# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define PLUS					24
# define MINUS					27
# define SPACEBAR				49
# define ESCAPE					53
# define PAD_ADD				69
# define PAD_SUB				78
# define PAD_1					83
# define PAD_2					84
# define PAD_3					85
# define LEFT					123
# define RIGHT					124
# define DOWN					125
# define UP						126
# define FN						279

# define LEFT_CLICK				1
# define SCROLL_UP				4
# define SCROLL_DOWN			5

# define MANDELBROT				1
# define JULIA					2
# define BURNINGSHIP			3

# define WIDTH					768
# define HEIGHT					WIDTH

# define THREADS				32
# define ITERATIONS				100

# define MIN_ZOOM				-10
# define MAX_ZOOM				360

# define MAX_COLOR				1000

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

typedef	struct	s_move
{
	int			x;
	int			y;
	int			click_x;
	int			click_y;
}				t_move;

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
	void		*win2;
	void		*img;
	int			*image;
	int			bpp;
	int			sl;
	int			endian;
	int			tx;
	int			ty;
	int			iteration;
	t_point		coord;
	double		zoom;
	int			zoom_lvl;
	t_double	zoom_c;
	t_double	translation;
	t_move		move;
	int			color_lvl;
	int			press;
	int			lock;
	double		c_r;
	double		c_i;
}				t_fract;

int				ft_fractals(t_fract *f);
void			*ft_mandelbrot(void *f);
void			*ft_julia(void *f);
void			*ft_burningship(void *f);
int				ft_keys(int keycode, t_fract *f);
int				ft_mouse(int button, int x, int y, t_fract *f);
int				ft_mouse_release(int button, int x, int y, t_fract *f);
int				ft_mouse_move(int x, int y, t_fract *f);
int				ft_mouse_zoom(int button, int x, int y, t_fract *f);
int				ft_zoom_in(t_fract *f);
int				ft_zoom_out(t_fract *f);
int				ft_color(double l);
int				ft_reset(t_fract *f);
int				ft_exit(t_fract *f);

int				ft_strcasecmp(const char *s1, const char *s2);

#endif
