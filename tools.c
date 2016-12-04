/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:05:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/04 03:23:14 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_frac *f)
{
	f->freeze = 'n';
	f->j.mlx.ptr = mlx_init();
	f->j.mlx.win = mlx_new_window(f->j.mlx.ptr, 800, 600, "fractol");
	f->j.mlx.img = mlx_new_image(f->j.mlx.ptr, 800, 600);
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

void	ft_print_fractal(t_frac frac)
{
	if (frac.id == 1)
	{
		ft_init_julia(&frac);
		ft_draw_julia(frac.j, 800, 600);
		mlx_hook(frac.j.mlx.win, 6, 64, &ft_hover_mouse_events_j, &frac);
		mlx_mouse_hook(frac.j.mlx.win, &ft_mouse_events_j, &frac);
		mlx_key_hook(frac.j.mlx.win, &ft_keyboard_events_j, &frac);
		mlx_loop(frac.j.mlx.ptr);
	}
	if (frac.id == 2)
	{
		ft_init_mandel(&frac);
		ft_draw_mandel(frac.m, 800, 600);
		mlx_mouse_hook(frac.m.mlx.win, &ft_mouse_events_m, &frac);
		mlx_key_hook(frac.m.mlx.win, &ft_keyboard_events_m, &frac);
		mlx_loop(frac.m.mlx.ptr);
	}
	if (frac.id == 3)
	{
		ft_init_sierpinski(&frac);
		ft_draw_sierpinski(frac.s, 800, 600);
		mlx_mouse_hook(frac.s.mlx.win, &ft_mouse_events_s, &frac);
		mlx_key_hook(frac.s.mlx.win, &ft_keyboard_events_s, &frac);
		mlx_loop(frac.s.mlx.ptr);
	}
}
