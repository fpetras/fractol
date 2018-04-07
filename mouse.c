/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:32:33 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/07 07:07:26 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_press(int button, int x, int y, t_fract *f)
{
	if (button == 1)
	{

	}
	if (button == 4 || button == 5)
		;
	return (0);
}

int		ft_mouse_release(int button, int x, int y, t_fract *f)
{
	(void)x;
	(void)y;
	if (button == 1)
		;
	return (0);
}

int		ft_mouse_move(int x, int y, t_fract *f)
{
	return (0);
}
