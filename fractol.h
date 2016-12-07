/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:54:16 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/07 02:35:52 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
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
	double			m_x;
	double			m_y;
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
	double			m_x;
	double			m_y;
	int				max;
}					t_mandel;

typedef struct		s_bship
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
	double			m_x;
	double			m_y;
	int				max;
}					t_bship;

typedef struct		s_frac
{
	char			freeze;
	t_julia			j;
	t_mandel		m;
	t_bship			bs;
}					t_frac;

void				ft_set_zero(double *nre, double *nim, double *oldre,
						double *oldim);
void				ft_process_julia(t_frac f);
void				ft_process_mandel(t_frac f);
void				ft_process_bship(t_frac f);
void				ft_init_julia(t_frac *f);
void				ft_init_mandel(t_frac *f);
void				ft_init_bship(t_frac *f);
void				ft_draw_julia(t_julia *j, int width, int height);
void				ft_draw_mandel(t_mandel *m, int width, int height);
void				ft_draw_bship(t_bship *bs, int width, int height);
int					ft_keyboard_events_j(int keycode, t_frac *f);
int					ft_keyboard_events_m(int keycode, t_frac *f);
int					ft_keyboard_events_bs(int keycode, t_frac *f);
int					ft_mouse_events_j(int button, int x, int y, t_frac *f);
int					ft_mouse_events_m(int button, int x, int y, t_frac *f);
int					ft_mouse_events_bs(int button, int x, int y, t_frac *f);
int					ft_hover_mouse_events_j(int x, int y, t_frac *f);
int					ft_exit_sig(int key, t_frac *f);

#endif
