/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:05:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/05 19:42:21 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_frac *f)
{
	f->freeze = 'n';
	f->j.mlx.ptr = mlx_init();
	f->j.mlx.win = mlx_new_window(f->j.mlx.ptr, 800, 600, "fractol");
	f->j.mlx.img = mlx_new_image(f->j.mlx.ptr, 800, 600);
	f->j.mlx.data = (int *)mlx_get_data_addr(f->j.mlx.img, &(f->j.mlx.bpp),
		&(f->j.mlx.size_line), &(f->j.mlx.endian));
	f->j.cre = -0.7;
	f->j.cim = 0.27015;
	f->j.nre = 0.0;
	f->j.nim = 0.0;
	f->j.oldre = 0.0;
	f->j.oldim = 0.0;
	f->j.zoom = 1.0;
	f->j.move_x = 0.0;
	f->j.move_y = 0.0;
	f->j.color = 0x00FF00;
	f->j.max = 300;
	f->j.p.x = 0;
	f->j.p.y = 0;
}

void	ft_init_mandel(t_frac *f)
{
	f->freeze = 'n';
	f->m.mlx.ptr = mlx_init();
	f->m.mlx.win = mlx_new_window(f->m.mlx.ptr, 800, 600, "fractol");
	f->m.mlx.img = mlx_new_image(f->m.mlx.ptr, 800, 600);
	f->m.mlx.data = (int *)mlx_get_data_addr(f->m.mlx.ptr, &(f->m.mlx.bpp),
		&(f->m.mlx.size_line), &(f->m.mlx.endian));
	f->m.cre = 0.0;
	f->m.cim = 0.0;
	f->m.nre = 0.0;
	f->m.nim = 0.0;
	f->m.oldre = 0.0;
	f->m.oldim = 0.0;
	f->m.zoom = 1.0;
	f->m.move_x = 0.0;
	f->m.move_y = 0.0;
	f->m.color = 0x0000FF;
	f->m.max = 300;
	f->m.p.x = 0;
	f->m.p.y = 0;
}

void	ft_init_sierpinski(t_frac *f)
{
	f->freeze = 'n';
	f->s.mlx.ptr = mlx_init();
	f->s.mlx.win = mlx_new_window(f->s.mlx.ptr, 800, 600, "fractol");
	f->s.mlx.img = mlx_new_image(f->s.mlx.ptr, 800, 600);
	f->s.mlx.data = (int *)mlx_get_data_addr(f->s.mlx.ptr, &(f->s.mlx.bpp),
		&(f->s.mlx.size_line), &(f->s.mlx.endian));
	f->s.zoom = 1;
	f->s.p.x = 0;
	f->s.p.y = 0;
}

void	ft_set_zero(t_mandel *m)
{
	m->nre = 0;
	m->nim = 0;
	m->oldre = 0;
	m->oldim = 0;
}

void	ft_print_fractal(t_frac f)
{
	if (f.id == 1)
	{
		ft_init_julia(&f);
		ft_draw_julia(&(f.j), 800, 600);
		mlx_put_image_to_window(f.j.mlx.ptr, f.j.mlx.win, f.j.mlx.img, 0, 0);
		mlx_hook(f.j.mlx.win, 6, 64, &ft_hover_mouse_events_j, &f);
		mlx_mouse_hook(f.j.mlx.win, &ft_mouse_events_j, &f);
		mlx_key_hook(f.j.mlx.win, &ft_keyboard_events_j, &f);
		mlx_loop(f.j.mlx.ptr);
	}
	if (f.id == 2)
	{
		ft_init_mandel(&f);
		ft_draw_mandel(&(f.m), 800, 600);
		mlx_put_image_to_window(f.m.mlx.ptr, f.m.mlx.win, f.m.mlx.img, 0, 0);
		mlx_mouse_hook(f.m.mlx.win, &ft_mouse_events_m, &f);
		mlx_key_hook(f.m.mlx.win, &ft_keyboard_events_m, &f);
		mlx_loop(f.m.mlx.ptr);
	}
	if (f.id == 3)
	{
		ft_init_sierpinski(&f);
		ft_draw_sierpinski(f.s, 800, 600);
		mlx_mouse_hook(f.s.mlx.win, &ft_mouse_events_s, &f);
		mlx_key_hook(f.s.mlx.win, &ft_keyboard_events_s, &f);
		mlx_loop(f.s.mlx.ptr);
	}
}
