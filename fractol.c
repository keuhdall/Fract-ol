/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:49:47 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/02 03:31:29 by lmarques         ###   ########.fr       */
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
			mlx_pixel_put(j.mlx.ptr, j.mlx.win, p.x, p.y, 0x00FF00 * i - 3 * i);
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
			mlx_pixel_put(m.mlx.ptr, m.mlx.win, p.x, p.y, 0x0000FF * i - 3 * i);
		}
	}
}

void	ft_draw_sierpinski(t_sierpinski s, int width, int height)
{
	t_point	p;

	p.y = -1;
	while (++p.y < height)
	{
		p.x = -1;
		while (++p.x < width)
		{
			if (!((p.x / 1) % 3 == 1 &&
				(p.y / 1) % 3 == 1) &&
				!((p.x / 3) % 3 == 1 &&
				(p.y / 3) % 3 == 1) &&
				!( (p.x / 9) % 3 == 1 &&
				(p.y / 9) % 3 == 1) &&
				!((p.x / 27) % 3 == 1 &&
				(p.y / 27) % 3 == 1) &&
				!((p.x / 81) % 3 == 1 &&
				(p.y / 81) % 3 == 1) &&
				!((p.x / 243) % 3 == 1 &&
				(p.y / 243) % 3 == 1))
				mlx_pixel_put(s.mlx.ptr, s.mlx.win, p.x + s.move_x,
					p.y + s.move_y, 0xFFFFFF);
		}
	}
}

int		ft_get_frac(char *arg)
{
	if (!ft_strcmp(arg, "j"))
		return (1);
	if (!ft_strcmp(arg, "m"))
		return (2);
	if (!ft_strcmp(arg, "s"))
		return (3);
	else
		return (-1);
}

int		main(int argc, char *argv[])
{
	t_frac	frac;

	if (argc != 2 || ft_get_frac(argv[1]) == -1)
	{
		ft_putendl("Wrong use of the program.\nUse :\n\t-j for Julia");
		ft_putendl("\t-m for Mandelbrot\n\t-s for Sierpinski");
		ft_putendl("The program only takes one parameter.");
		return (0);
	}
	else
		frac.id = ft_get_frac(argv[1]);
	ft_print_fractal(frac);
	return (0);
}
