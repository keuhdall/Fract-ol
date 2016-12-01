/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:49:47 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/01 17:37:15 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_julia(t_julia j, int width, int height)
{
	t_point	p;
	int		i;
	
	p.y = -1;
	while (++p.y < height)
	{
		p.x = -1;
		while (++p.x < width)
		{
			i = -1;
			j.nRe = 1.5 * (p.x - width / 2) / (0.5 * j.zoom * width) + j.move_x;
			j.nIm = (p.y - height / 2) / (0.5 * j.zoom * height) + j.move_y;
			while (++i < j.max)
			{
				j.oldRe = j.nRe;
				j.oldIm = j.nIm;
				j.nRe = j.oldRe * j.oldRe - j.oldIm * j.oldIm + j.cRe;
				j.nIm = 2 * j.oldRe * j.oldIm + j.cIm;
				if ((j.nRe * j.nRe + j.nIm * j.nIm) > 4)
					break ;
			}
			j.color = 0x00FF00 * i - 3 * i;
			mlx_pixel_put(j.mlx.ptr, j.mlx.win, p.x, p.y, j.color);
		}
	}
}

void	ft_draw_mandel(t_mandel m, int width, int height)
{
	t_point	p;
	int		i;

	p.y = -1;
	while (++p.y < height)
	{
		p.x = -1;
		while (++p.x < width)
		{
			m.cRe = 1.5 * (p.x - width / 2) / (0.5 * m.zoom * width) + m.move_x;
			m.cIm = (p.y - height / 2) / (0.5 * m.zoom * height) + m.move_y;
			m.nRe = m.nIm = m.oldRe = m.oldIm = 0;
			i = -1;
			while (++i < m.max)
			{
				m.oldRe = m.nRe;
				m.oldIm = m.nIm;
				m.nRe = m.oldRe * m.oldRe - m.oldIm * m.oldIm + m.cRe;
				m.nIm = 2 * m.oldRe * m.oldIm + m.cIm;
				if ((m.nRe * m.nRe + m.nIm * m.nIm) > 4)
					break ;
			}
			m.color = 0x0000FF * i - 3 * i;
			mlx_pixel_put(m.mlx.ptr, m.mlx.win, p.x, p.y, m.color);
		}
	}
}

int		main(int argc, char *argv[])
{
	int			err;
	//t_julia		julia;
	t_mandel	mandel;

	err = 0;
	//ft_init_julia(&julia);
	ft_init_mandel(&mandel);
	ft_draw_mandel(mandel, 800, 600);
	mlx_loop(mandel.mlx.ptr);
	//ft_draw_julia(julia, 800, 600);
	//mlx_loop(julia.mlx.ptr);
	if (argv[0])
		argc++;
	err++;
	return (0);
}
