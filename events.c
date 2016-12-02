/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/02 17:59:56 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_hover_mouse_events(int x, int y, t_frac *f)
{
	if (f->freeze == 'n')
		printf("x = %d y = %d\n", x, y);
	if (f->freeze == 'n')
	{
		f->j.cre = -0.7 + (double)x / 800;
		f->j.cim = 0.27015 + (double)y / 600;
		mlx_clear_window(f->j.mlx.ptr, f->j.mlx.win);
		ft_draw_julia(f->j, 800, 600);
	}
	return (0);
}

int		ft_keyboard_events(int keycode, t_frac *f)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	return (0);
}
