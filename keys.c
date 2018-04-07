/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:32:19 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/07 07:45:23 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_keys(int keycode, t_fract *f)
{
	if (keycode == ESCAPE)
		ft_exit(f);
	if (keycode == KEY_R)
		;
	if (keycode == SPACEBAR)
		;
	if (keycode == LEFT || keycode == RIGHT || keycode == DOWN || keycode == UP)
		;
	return (0);
}
