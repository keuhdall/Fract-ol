/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:05:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/02 17:34:36 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_frac *frac)
{
	frac->freeze = 'n';
	frac->j.mlx.ptr = mlx_init();
	frac->j.mlx.win = mlx_new_window(frac->j.mlx.ptr, 800, 600, "fractol");
	frac->j.cre = -0.7;
	frac->j.cim = 0.27015;
	frac->j.nre = 0.0;
	frac->j.nim = 0.0;
	frac->j.oldre = 0.0;
	frac->j.oldim = 0.0;
	frac->j.zoom = 1.0;
	frac->j.move_x = 0.0;
	frac->j.move_y = 0.0;
	frac->j.color = 0x00FF00;
	frac->j.max = 300;
}

void	ft_init_mandel(t_frac *frac)
{
	frac->freeze = 'n';
	frac->m.mlx.ptr = mlx_init();
	frac->m.mlx.win = mlx_new_window(frac->m.mlx.ptr, 800, 600, "fractol");
	frac->m.cre = 0.0;
	frac->m.cim = 0.0;
	frac->m.nre = 0.0;
	frac->m.nim = 0.0;
	frac->m.oldre = 0.0;
	frac->m.oldim = 0.0;
	frac->m.zoom = 1.0;
	frac->m.move_x = 0.0;
	frac->m.move_y = 0.0;
	frac->m.color = 0x0000FF;
	frac->m.max = 300;
}

void	ft_init_sierpinski(t_frac *frac)
{
	frac->freeze = 'n';
	frac->s.mlx.ptr = mlx_init();
	frac->s.mlx.win = mlx_new_window(frac->s.mlx.ptr, 800, 600, "fractol");
	frac->s.move_x = 0;
	frac->s.move_y = 0;
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
		mlx_hook(frac.j.mlx.win, 6, 64, &ft_hover_mouse_events, &frac);
		mlx_key_hook(frac.j.mlx.win, &ft_keyboard_events, &frac);
		mlx_loop(frac.j.mlx.ptr);
	}
	if (frac.id == 2)
	{
		ft_init_mandel(&frac);
		ft_draw_mandel(frac.m, 800, 600);
		mlx_key_hook(frac.m.mlx.win, &ft_keyboard_events, &frac);
		mlx_loop(frac.m.mlx.ptr);
	}
	if (frac.id == 3)
	{
		ft_init_sierpinski(&frac);
		ft_draw_sierpinski(frac.s, 800, 600);
		mlx_key_hook(frac.s.mlx.win, &ft_keyboard_events, &frac);
		mlx_loop(frac.s.mlx.ptr);
	}
}
