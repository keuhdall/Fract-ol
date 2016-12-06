/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:54:16 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/06 00:39:04 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx/mlx.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_meta
{
	void			*ptr;
	void			*win;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
	int				*data;
}					t_meta;

typedef struct		s_julia
{
	t_meta			mlx;
	t_point			p;
	double			cre;
	double			cim;
	double			nre;
	double			nim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			move_x;
	double			move_y;
	int				color;
	int				max;
}					t_julia;

typedef struct		s_mandel
{
	t_meta			mlx;
	t_point			p;
	double			cre;
	double			cim;
	double			nre;
	double			nim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			move_x;
	double			move_y;
	int				color;
	int				max;
}					t_mandel;

typedef struct		s_sierpinski
{
	t_meta			mlx;
	t_point			p;
	int				zoom;
}					t_sierpinski;

typedef struct		s_frac
{
	int				id;
	char			freeze;
	t_julia			j;
	t_mandel		m;
	t_sierpinski	s;
}					t_frac;

void				ft_set_zero(t_mandel *m);
void				ft_print_fractal(t_frac frac);
void				ft_draw_julia(t_julia *j, int width, int height);
void				ft_draw_mandel(t_mandel *m, int width, int height);
void				ft_draw_sierpinski(t_sierpinski *s, int width, int height);
int					ft_keyboard_events_j(int keycode, t_frac *f);
int					ft_keyboard_events_m(int keycode, t_frac *f);
int					ft_keyboard_events_s(int keycode, t_frac *f);
int					ft_mouse_events_j(int button, int x, int y, t_frac *f);
int					ft_mouse_events_m(int button, int x, int y, t_frac *f);
int					ft_mouse_events_s(int button, int x, int y, t_frac *f);
int					ft_hover_mouse_events_j(int x, int y, t_frac *f);

#endif
