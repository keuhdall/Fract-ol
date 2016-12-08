/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:50:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/08 14:49:30 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_process_julia(t_frac f)
{
	ft_init_julia(&f);
	ft_draw_julia(&f, 800, 600);
	mlx_put_image_to_window(f.mlx.ptr, f.mlx.win, f.mlx.img, 0, 0);
	mlx_hook(f.mlx.win, 6, 64, &ft_hover_mouse_events_j, &f);
	mlx_hook(f.mlx.win, 17, 1L << 17, &ft_exit_sig, &f);
	mlx_mouse_hook(f.mlx.win, &ft_mouse_events_j, &f);
	mlx_key_hook(f.mlx.win, &ft_keyboard_events_j, &f);
	mlx_loop(f.mlx.ptr);
}

void	ft_reset_julia(t_frac *f)
{
	f->freeze = 'y';
	f->max = 50;
	f->zoom = 1;
	f->m_x = 0;
	f->m_y = 0;
	f->cre = -0.7;
	f->cim = 0.27015;
}

int		ft_hover_mouse_events_j(int x, int y, t_frac *f)
{
	if (f->freeze == 'n')
	{
		f->cre = -0.7 + (double)x / 800;
		f->cim = 0.27015 + (double)y / 600;
		mlx_clear_window(f->mlx.ptr, f->mlx.win);
		ft_draw_julia(f, 800, 600);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
	}
	return (0);
}

int		ft_mouse_events_j(int button, int x, int y, t_frac *f)
{
	if (button == 1 || button == 4)
	{
		f->m_x += 0.002 * (400 - x) / f->zoom;
		f->m_y -= 0.002 * (300 - y) / f->zoom;
		if (button == 4)
			f->zoom *= 2;
	}
	if (button == 5)
		f->zoom = f->zoom <= 1 ? 1 : f->zoom / 2;
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	ft_draw_julia(f, 800, 600);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
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
		f->max += 10;
	if (keycode == 27)
		f->max = f->max <= 50 ? 50 : f->max - 10;
	if (keycode == 123 || keycode == 124)
		f->m_x = keycode == 123 ? f->m_x + 0.5 /
			f->zoom : f->m_x - 0.5 / f->zoom;
	if (keycode == 125 || keycode == 126)
		f->m_y = keycode == 125 ? f->m_y + 0.5 /
			f->zoom : f->m_y - 0.5 / f->zoom;
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	ft_draw_julia(f, 800, 600);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
	return (0);
}
