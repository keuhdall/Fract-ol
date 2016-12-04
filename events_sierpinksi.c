/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_sierpinksi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/04 03:21:57 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_mouse_events_s(int button, int x, int y, t_frac *f)
{
	mlx_clear_window(f->s.mlx.ptr, f->s.mlx.win);
	if (button == 1 || button == 4 || button == 5)
	{
		f->s.p.x = 400 - x;
		f->s.p.y = 300 - y;
		if (button == 4)
			f->s.zoom++;
		if (button == 5)
			f->s.zoom <= 1 ? f->s.zoom = 1 : f->s.zoom--;
	}
	ft_draw_sierpinski(f->s, 800, 600);
	return (0);
}

int		ft_keyboard_events_s(int keycode, t_frac *f)
{
	mlx_clear_window(f->s.mlx.ptr, f->s.mlx.win);
	if (keycode == 53)
		exit(1);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	ft_draw_sierpinski(f->s, 800, 600);
	return (0);
}
