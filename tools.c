/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:05:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/07 02:36:14 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_frac *f)
{
	f->freeze = 'n';
	f->j.mlx.ptr = mlx_init();
	f->j.mlx.win = mlx_new_window(f->j.mlx.ptr, 800, 600, "fractol");
	f->j.mlx.img = mlx_new_image(f->j.mlx.ptr, 800, 600);
	f->j.mlx.data = (int *)mlx_get_data_addr(f->j.mlx.img, &(f->j.mlx.bpp),
		&(f->j.mlx.size_line), &(f->j.mlx.endian));
	f->j.cre = -0.7;
	f->j.cim = 0.27015;
	f->j.nre = 0.0;
	f->j.nim = 0.0;
	f->j.oldre = 0.0;
	f->j.oldim = 0.0;
	f->j.zoom = 1.0;
	f->j.m_x = 0.0;
	f->j.m_y = 0.0;
	f->j.max = 50;
	f->j.p.x = 0;
	f->j.p.y = 0;
}

void	ft_init_mandel(t_frac *f)
{
	f->freeze = 'n';
	f->m.mlx.ptr = mlx_init();
	f->m.mlx.win = mlx_new_window(f->m.mlx.ptr, 800, 600, "fractol");
	f->m.mlx.img = mlx_new_image(f->m.mlx.ptr, 800, 600);
	f->m.mlx.data = (int *)mlx_get_data_addr(f->m.mlx.img, &(f->m.mlx.bpp),
		&(f->m.mlx.size_line), &(f->m.mlx.endian));
	f->m.cre = 0.0;
	f->m.cim = 0.0;
	f->m.nre = 0.0;
	f->m.nim = 0.0;
	f->m.oldre = 0.0;
	f->m.oldim = 0.0;
	f->m.zoom = 1.0;
	f->m.m_x = 0.0;
	f->m.m_y = 0.0;
	f->m.max = 50;
	f->m.p.x = 0;
	f->m.p.y = 0;
}

void	ft_init_bship(t_frac *f)
{
	f->freeze = 'n';
	f->bs.mlx.ptr = mlx_init();
	f->bs.mlx.win = mlx_new_window(f->bs.mlx.ptr, 800, 600, "fractol");
	f->bs.mlx.img = mlx_new_image(f->bs.mlx.ptr, 800, 600);
	f->bs.mlx.data = (int *)mlx_get_data_addr(f->bs.mlx.img, &(f->bs.mlx.bpp),
		&(f->bs.mlx.size_line), &(f->bs.mlx.endian));
	f->bs.cre = 0.0;
	f->bs.cim = 0.0;
	f->bs.nre = 0.0;
	f->bs.nim = 0.0;
	f->bs.oldre = 0.0;
	f->bs.oldim = 0.0;
	f->bs.zoom = 1.0;
	f->bs.m_x = 0.0;
	f->bs.m_y = 0.0;
	f->bs.max = 50;
	f->bs.p.x = 0;
	f->bs.p.y = 0;
}

void	ft_set_zero(double *nre, double *nim, double *oldre, double *oldim)
{
	*nre = 0;
	*nim = 0;
	*oldre = 0;
	*oldim = 0;
}

int		ft_exit_sig(int key, t_frac *f)
{
	if (f->freeze == 'y')
		exit (1);
	else
		exit (1);
	key++;
	return(0);
}
