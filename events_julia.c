/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/06 23:34:54 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_process_julia(t_frac f)
{
	ft_init_julia(&f);
	ft_draw_julia(&(f.j), 800, 600);
	mlx_put_image_to_window(f.j.mlx.ptr, f.j.mlx.win, f.j.mlx.img, 0, 0);
	mlx_hook(f.j.mlx.win, 6, 64, &ft_hover_mouse_events_j, &f);
	mlx_mouse_hook(f.j.mlx.win, &ft_mouse_events_j, &f);
	mlx_key_hook(f.j.mlx.win, &ft_keyboard_events_j, &f);
	mlx_loop(f.j.mlx.ptr);
}

void	ft_reset_julia(t_frac *f)
{
	f->freeze = 'y';
	f->j.max = 50;
	f->j.zoom = 1;
	f->j.m_x = 0;
	f->j.m_y = 0;
	f->j.cre = -0.7;
	f->j.cim = 0.27015;
}

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
	if (button == 1 || button == 4)
	{
		f->j.m_x += 0.002 * (400 - x) / f->j.zoom;
		f->j.m_y -= 0.002 * (300 - y) / f->j.zoom;
		if (button == 4)
			f->j.zoom *= 2;
	}
	if (button == 5)
		f->j.zoom = f->j.zoom <= 1 ? 1 : f->j.zoom / 2;
	mlx_clear_window(f->j.mlx.ptr, f->j.mlx.win);
	ft_draw_julia(&(f->j), 800, 600);
	mlx_put_image_to_window(f->j.mlx.ptr, f->j.mlx.win, f->j.mlx.img, 0, 0);
	return (0);
}

int		ft_keyboard_events_j(int keycode, t_frac *f)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 15)
		ft_reset_julia(f);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	if (keycode == 24)
		f->j.max += 10;
	if (keycode == 27)
		f->j.max = f->j.max <= 50 ? 50 : f->j.max - 10;
	mlx_clear_window(f->j.mlx.ptr, f->j.mlx.win);
	ft_draw_julia(&(f->j), 800, 600);
	mlx_put_image_to_window(f->j.mlx.ptr, f->j.mlx.win, f->j.mlx.img, 0, 0);
	return (0);
}
