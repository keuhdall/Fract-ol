/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:54:16 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/01 17:36:50 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx/mlx.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_meta
{
	void		*ptr;
	void		*win;
}				t_meta;

typedef struct	s_julia
{
	t_meta		mlx;
	double		cRe;
	double		cIm;
	double		nRe;
	double		nIm;
	double		oldRe;
	double		oldIm;
	double		zoom;
	double		move_x;
	double		move_y;
	int			color;
	int			max;
}				t_julia;

typedef struct	s_mandel
{
	t_meta		mlx;
	double		cRe;
	double		cIm;
	double		nRe;
	double		nIm;
	double		oldRe;
	double		oldIm;
	double		zoom;
	double		move_x;
	double		move_y;
	int			color;
	int			max;
}				t_mandel;

void			ft_init_julia(t_julia *julia);
void			ft_init_mandel(t_mandel *mandel);

#endif
