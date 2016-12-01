/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:05:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/01 16:10:16 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_julia *julia)
{
	julia->mlx.ptr = mlx_init();
	julia->mlx.win = mlx_new_window(julia->mlx.ptr, 800, 600, "fractol");
	julia->cRe = -0.7;
	julia->cIm = 0.27015;
	julia->nRe = 0.0;
	julia->nIm = 0.0;
	julia->oldRe = 0.0;
	julia->oldIm = 0.0;
	julia->zoom = 1.0;
	julia->move_x = 0.0;
	julia->move_y = 0.0;
	julia->color = 0x00FF00;
	julia->max = 300;
}

void	ft_init_mandel(t_mandel *mandel)
{
	mandel->mlx.ptr = mlx_init();
	mandel->mlx.win = mlx_new_window(mandel->mlx.ptr, 800, 600, "fractol");
	mandel->cRe = 0.0;
	mandel->cIm = 0.0;
	mandel->nRe = 0.0;
	mandel->nIm = 0.0;
	mandel->oldRe = 0.0;
	mandel->oldIm = 0.0;
	mandel->zoom = 1.0;
	mandel->move_x = 0.0;
	mandel->move_y = 0.0;
	mandel->color = 0x0000FF;
	mandel->max = 300;
}

int		ft_keyboard_event(int keycode)
{
	keycode++;
	return (0);
}
