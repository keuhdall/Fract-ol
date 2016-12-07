/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/07 14:17:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_process_bship(t_frac f)
{
	ft_init_bship(&f);
	ft_draw_bship(&(f.bs), 800, 600);
	mlx_put_image_to_window(f.bs.mlx.ptr, f.bs.mlx.win, f.bs.mlx.img, 0, 0);
	mlx_hook(f.bs.mlx.win, 17, 1L << 17, &ft_exit_sig, &f);
	mlx_mouse_hook(f.bs.mlx.win, &ft_mouse_events_bs, &f);
	mlx_key_hook(f.bs.mlx.win, &ft_keyboard_events_bs, &f);
	mlx_loop(f.bs.mlx.ptr);
}

void	ft_reset_bs(t_frac *f)
{
	f->freeze = 'y';
	f->bs.max = 50;
	f->bs.zoom = 1;
	f->bs.m_x = 0;
	f->bs.m_y = 0;
}

int		ft_mouse_events_bs(int button, int x, int y, t_frac *f)
{
	mlx_clear_window(f->bs.mlx.ptr, f->bs.mlx.win);
	if (button == 1 || button == 4)
	{
		f->bs.m_x += 0.002 * (400 - x) / f->bs.zoom;
		f->bs.m_y += 0.002 * (300 - y) / f->bs.zoom;
		if (button == 4)
			f->bs.zoom *= 2;
	}
	if (button == 5)
		f->bs.zoom = f->bs.zoom <= 1 ? 1 : f->bs.zoom / 2;
	ft_draw_bship(&(f->bs), 800, 600);
	mlx_put_image_to_window(f->bs.mlx.ptr, f->bs.mlx.win, f->bs.mlx.img, 0, 0);
	return (0);
}

int		ft_keyboard_events_bs(int keycode, t_frac *f)
{
	mlx_clear_window(f->bs.mlx.ptr, f->bs.mlx.win);
	if (keycode == 53)
		exit(1);
	if (keycode == 15)
		ft_reset_bs(f);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	if (keycode == 24)
		f->bs.max += 10;
	if (keycode == 27)
		f->bs.max = f->bs.max <= 40 ? 40 : f->bs.max - 10;
	ft_draw_bship(&(f->bs), 800, 600);
	mlx_put_image_to_window(f->bs.mlx.ptr, f->bs.mlx.win, f->bs.mlx.img, 0, 0);
	return (0);
}
