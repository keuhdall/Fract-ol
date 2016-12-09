/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/09 17:36:33 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_process_mandel(t_frac f)
{
	ft_init_mandel(&f);
	ft_draw_mandel(&f, 800, 600);
	mlx_put_image_to_window(f.mlx.ptr, f.mlx.win, f.mlx.img, 0, 0);
	mlx_hook(f.mlx.win, 17, 1L << 17, &ft_exit_sig, &f);
	mlx_mouse_hook(f.mlx.win, &ft_mouse_events_m, &f);
	mlx_key_hook(f.mlx.win, &ft_keyboard_events_m, &f);
	mlx_loop(f.mlx.ptr);
}

void	ft_reset_mandel(t_frac *f)
{
	f->freeze = 'y';
	f->max = 50;
	f->zoom = 1;
	f->m_x = 0;
	f->m_y = 0;
}

int		ft_mouse_events_m(int button, int x, int y, t_frac *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	if (button == 1 || button == 4)
	{
		f->m_x += 0.002 * (400 - x) / f->zoom;
		f->m_y += 0.002 * (300 - y) / f->zoom;
		if (button == 4)
			f->zoom *= 2;
	}
	if (button == 5)
		f->zoom = f->zoom <= 1 ? 1 : f->zoom / 2;
	ft_draw_mandel(f, 800, 600);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
	return (0);
}

int		ft_keyboard_events_m(int keycode, t_frac *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	if (keycode == 53)
		exit(1);
	if (keycode == 15)
		ft_reset_mandel(f);
	if (keycode == 49)
		f->freeze = f->freeze == 'n' ? 'y' : 'n';
	if (keycode == 24)
		f->max += 10;
	if (keycode == 27)
		f->max = f->max <= 40 ? 40 : f->max - 10;
	if (keycode == 123 || keycode == 124)
		f->m_x = keycode == 123 ? f->m_x + 0.5 /
			f->zoom : f->m_x - 0.5 / f->zoom;
	if (keycode == 125 || keycode == 126)
		f->m_y = keycode == 125 ? f->m_y - 0.5 /
			f->zoom : f->m_y + 0.5 / f->zoom;
	ft_draw_mandel(f, 800, 600);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
	return (0);
}
