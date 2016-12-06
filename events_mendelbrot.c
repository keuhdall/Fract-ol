/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mendelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/06 23:40:11 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_process_mandel(t_frac f)
{
	ft_init_mandel(&f);
	ft_draw_mandel(&(f.m), 800, 600);
	mlx_put_image_to_window(f.m.mlx.ptr, f.m.mlx.win, f.m.mlx.img, 0, 0);
	mlx_mouse_hook(f.m.mlx.win, &ft_mouse_events_m, &f);
	mlx_key_hook(f.m.mlx.win, &ft_keyboard_events_m, &f);
	mlx_loop(f.m.mlx.ptr);
}

void	ft_reset_mandel(t_frac *f)
{
	f->freeze = 'y';
	f->m.max = 50;
	f->m.zoom = 1;
	f->m.m_x = 0;
	f->m.m_y = 0;
}

int		ft_mouse_events_m(int button, int x, int y, t_frac *f)
{
	mlx_clear_window(f->m.mlx.ptr, f->m.mlx.win);
	if (button == 1 || button == 4)
	{
		f->m.m_x += 0.002 * (400 - x) / f->m.zoom;
		f->m.m_y += 0.002 * (300 - y) / f->m.zoom;
		if (button == 4)
			f->m.zoom *= 2;
	}
	if (button == 5)
		f->m.zoom = f->m.zoom <= 1 ? 1 : f->m.zoom / 2;
	ft_draw_mandel(&(f->m), 800, 600);
	mlx_put_image_to_window(f->m.mlx.ptr, f->m.mlx.win, f->m.mlx.img, 0, 0);
	return (0);
}

int		ft_keyboard_events_m(int keycode, t_frac *f)
{
	mlx_clear_window(f->m.mlx.ptr, f->m.mlx.win);
	if (keycode == 53)
		exit(1);
	if (keycode == 15)
		ft_reset_mandel(f);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	if (keycode == 24)
		f->m.max += 10;
	if (keycode == 27)
		f->m.max = f->m.max <= 40 ? 40 : f->m.max - 10;
	ft_draw_mandel(&(f->m), 800, 600);
	mlx_put_image_to_window(f->m.mlx.ptr, f->m.mlx.win, f->m.mlx.img, 0, 0);
	return (0);
}
