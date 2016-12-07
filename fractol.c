/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:49:47 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/07 02:41:35 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_julia(t_julia *j, int width, int height)
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
			j->nre = 1.5 * (p.x - width / 2) / (0.5 * j->zoom * width) - j->m_x;
			j->nim = (p.y - height / 2) / (0.5 * j->zoom * height) + j->m_y;
			while (++i < j->max)
			{
				j->oldre = j->nre;
				j->oldim = j->nim;
				j->nre = j->oldre * j->oldre - j->oldim * j->oldim + j->cre;
				j->nim = 2 * j->oldre * j->oldim + j->cim;
				if ((j->nre * j->nre + j->nim * j->nim) > 4)
					break ;
			}
			j->mlx.data[p.y * 800 + p.x] = i == j->max ? 0 : i * 500;
		}
	}
}

void	ft_draw_mandel(t_mandel *m, int width, int height)
{
	t_point	p;
	int		i;

	p.y = -1;
	while (++p.y < height)
	{
		p.x = -1;
		while (++p.x < width)
		{
			m->cre = 1.5 * (p.x - width / 2) / (0.5 * m->zoom * width) - m->m_x;
			m->cim = (p.y - height / 2) / (0.5 * m->zoom * height) - m->m_y;
			ft_set_zero(&(m->nre), &(m->nim), &(m->oldre), &(m->oldim));
			i = -1;
			while (++i < m->max)
			{
				m->oldre = m->nre;
				m->oldim = m->nim;
				m->nre = m->oldre * m->oldre - m->oldim * m->oldim + m->cre;
				m->nim = 2 * m->oldre * m->oldim + m->cim;
				if ((m->nre * m->nre + m->nim * m->nim) > 4)
					break ;
			}
			m->mlx.data[p.y * 800 + p.x] = i == m->max ? 0 : 255 * i - 3 * i;
		}
	}
}

void	ft_draw_bship(t_bship *bs, int w, int h)
{
	t_point	p;
	int		i;

	p.y = -1;
	while (++p.y < h)
	{
		p.x = -1;
		while (++p.x < w)
		{
			bs->cre = 1.5 * (p.x - w / 2) / (0.5 * bs->zoom * w) - bs->m_x;
			bs->cim = (p.y - h / 2) / (0.5 * bs->zoom * h) - bs->m_y;
			ft_set_zero(&(bs->nre), &(bs->nim), &(bs->oldre), &(bs->oldim));
			i = -1;
			while (++i < bs->max)
			{
				bs->oldre = bs->nre;
				bs->oldim = bs->nim;
				bs->nre = pow(bs->oldre, 2) - bs->oldim * bs->oldim + bs->cre;
				bs->nim = 2 * fabs(bs->oldre * bs->oldim) + bs->cim;
				if ((bs->nre * bs->nre + bs->nim * bs->nim) > 4)
					break ;
			}
			bs->mlx.data[p.y * 800 + p.x] = i == bs->max ? 0 : 255 * i - 3 * i;
		}
	}
}

int		ft_get_frac(char *arg)
{
	t_frac	f;

	f.freeze = 'n';
	if (!ft_strcmp(arg, "-j"))
	{
		ft_process_julia(f);
		return (0);
	}
	if (!ft_strcmp(arg, "-m"))
	{
		ft_process_mandel(f);
		return (0);
	}
	if (!ft_strcmp(arg, "-bs"))
	{
		ft_process_bship(f);
		return (0);
	}
	else
		return (-1);
}

int		main(int argc, char *argv[])
{
	if (argc != 2 || ft_get_frac(argv[1]) == -1)
	{
		ft_putendl("Wrong use of the program.\nUse :\n\t-j for Julia");
		ft_putendl("\t-m for Mandelbrot\n\t-bs for Burning Ship");
		ft_putendl("The program only takes one parameter.");
		return (0);
	}
	return (0);
}
