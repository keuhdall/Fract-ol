/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mendelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/05 19:19:34 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_mouse_events_m(int button, int x, int y, t_frac *f)
{
	mlx_clear_window(f->m.mlx.ptr, f->m.mlx.win);
	if (button == 1 || button == 4 || button == 5)
	{
		f->m.p.x = 400 - x;
		f->m.p.y = 300 - y;
		if (button == 4)
			f->m.zoom++;
		if (button == 5)
			f->m.zoom <= 1 ? f->m.zoom = 1 : f->m.zoom--;
	}
	ft_draw_mandel(&(f->m), 800, 600);
	mlx_put_image_to_window(f->m.mlx.ptr, f->m.mlx.win, f->m.mlx.img, 0, 0);
	return (0);
}

int		ft_keyboard_events_m(int keycode, t_frac *f)
{
	mlx_clear_window(f->m.mlx.ptr, f->m.mlx.win);
	if (keycode == 53)
		exit(1);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	if (keycode == 24)
		f->m.max += 10;
	if (keycode == 27)
		f->m.max -= 10;
	ft_draw_mandel(&(f->m), 800, 600);
	mlx_put_image_to_window(f->m.mlx.ptr, f->m.mlx.win, f->m.mlx.img, 0, 0);
	return (0);
}
