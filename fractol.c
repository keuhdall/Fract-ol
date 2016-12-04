/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:49:47 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/04 04:31:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color(int r, int g, int b)
{
	return(((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}

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
			j.nre = 1.5 * (p.x - width / 2) / (0.5 * j.zoom * width) + j.move_x;
			j.nim = (p.y - height / 2) / (0.5 * j.zoom * height) + j.move_y;
			while (++i < j.max)
			{
				j.oldre = j.nre;
				j.oldim = j.nim;
				j.nre = j.oldre * j.oldre - j.oldim * j.oldim + j.cre;
				j.nim = 2 * j.oldre * j.oldim + j.cim;
				if ((j.nre * j.nre + j.nim * j.nim) > 4)
					break ;
			}
			mlx_pixel_put(j.mlx.ptr, j.mlx.win, p.x + j.p.x, p.y + j.p.y,
				ft_color(i % 256, 255, 255 * (i < j.max)));
			//0xFF00FF >> i / 10);
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
			m.cre = 1.5 * (p.x - width / 2) / (0.5 * m.zoom * width) + m.move_x;
			m.cim = (p.y - height / 2) / (0.5 * m.zoom * height) + m.move_y;
			ft_set_zero(&m);
			i = -1;
			while (++i < m.max)
			{
				m.oldre = m.nre;
				m.oldim = m.nim;
				m.nre = m.oldre * m.oldre - m.oldim * m.oldim + m.cre;
				m.nim = 2 * m.oldre * m.oldim + m.cim;
				if ((m.nre * m.nre + m.nim * m.nim) > 4)
					break ;
			}
			mlx_pixel_put(m.mlx.ptr, m.mlx.win, p.x + m.p.x, p.y + m.p.y, 0x0000FF * i - 3 * i);
		}
	}
}
/*
   void	ft_draw_sierpinski(t_sierpinski s, int width, int height)
   {
   t_point	p;

   p.y = -1;
   while (++p.y < height)
   {
   p.x = -1;
   while (++p.x < width)
   {
   if (!((p.x / 1) % s.zoom == 1 &&
   (p.y / 1) % s.zoom == 1) &&
   !((p.x / 3) % s.zoom == 1 &&
   (p.y / 3) % s.zoom == 1) &&
   !((p.x / 9) % s.zoom == 1 &&
   (p.y / 9) % s.zoom == 1) &&
   !((p.x / 27) % s.zoom == 1 &&
   (p.y / 27) % s.zoom == 1) &&
   !((p.x / 81) % s.zoom == 1 &&
   (p.y / 81) % s.zoom == 1) &&
   !((p.x / 243) % s.zoom == 1 &&
   (p.y / 243) % s.zoom == 1))
   mlx_pixel_put(s.mlx.ptr, s.mlx.win, p.x + s.p.x,
   p.y + s.p.y, 0xFFFFFF);
   }
   }
   }
   */

void	ft_draw_sierpinski(t_sierpinski s, int width, int height)
{
	t_point	p;

	p.y = -1;
	while (++p.y < height + s.zoom)
	{
		p.x = -1;
		while (++p.x < width + s.zoom)
		{
			if (p.x & p.y)
				mlx_pixel_put(s.mlx.ptr, s.mlx.win, p.x + s.p.x, p.y + s.p.y, 0xFFFFFF);
		}
	}
}

int		ft_get_frac(char *arg)
{
	if (!ft_strcmp(arg, "-j"))
		return (1);
	if (!ft_strcmp(arg, "-m"))
		return (2);
	if (!ft_strcmp(arg, "-s"))
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
