/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/05 20:55:06 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_hover_mouse_events_j(int x, int y, t_frac *f)
{
	if (f->freeze == 'n')
	{
		f->j.cre = -0.7 + (double)x / 800;
		f->j.cim = 0.27015 + (double)y / 600;
		mlx_clear_window(f->j.mlx.ptr, f->j.mlx.win);
		ft_draw_julia(&(f->j), 800, 600);
		mlx_put_image_to_window(f->j.mlx.ptr, f->j.mlx.win, f->j.mlx.img, 0, 0);
	}
	return (0);
}

int		ft_mouse_events_j(int button, int x, int y, t_frac *f)
{
	mlx_clear_window(f->j.mlx.ptr, f->j.mlx.win);
	if (button == 1 || button == 4 || button == 5)
	{
		f->j.p.x = 400 - x;
		f->j.p.y = 300 - y;
		if (button == 4)
			f->j.zoom++;
		if (button == 5)
			f->j.zoom <= 1 ? f->j.zoom = 1 : f->j.zoom--;
	}
	ft_draw_julia(&(f->j), 800, 600);
	mlx_put_image_to_window(f->j.mlx.ptr, f->j.mlx.win, f->j.mlx.img, 0, 0);
	return (0);
}

int		ft_keyboard_events_j(int keycode, t_frac *f)
{
	mlx_clear_window(f->j.mlx.ptr, f->j.mlx.win);
	if (keycode == 53)
		exit(1);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	if (keycode == 24)
		f->j.max += 10;
	if (keycode == 27)
		f->j.max -= 10;
	ft_draw_julia(&(f->j), 800, 600);
	mlx_put_image_to_window(f->j.mlx.ptr, f->j.mlx.win, f->j.mlx.img, 0, 0);
	return (0);
}
