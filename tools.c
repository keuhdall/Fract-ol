/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:05:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/08 14:52:28 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(t_frac *f)
{
	f->freeze = 'n';
	f->mlx.ptr = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.ptr, 800, 600, "fractol");
	f->mlx.img = mlx_new_image(f->mlx.ptr, 800, 600);
	f->mlx.data = (int *)mlx_get_data_addr(f->mlx.img, &(f->mlx.bpp),
		&(f->mlx.size_line), &(f->mlx.endian));
	f->cre = -0.7;
	f->cim = 0.27015;
	f->nre = 0.0;
	f->nim = 0.0;
	f->oldre = 0.0;
	f->oldim = 0.0;
	f->zoom = 1.0;
	f->m_x = 0.0;
	f->m_y = 0.0;
	f->max = 50;
	f->p.x = 0;
	f->p.y = 0;
}

void	ft_init_mandel(t_frac *f)
{
	f->freeze = 'n';
	f->mlx.ptr = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.ptr, 800, 600, "fractol");
	f->mlx.img = mlx_new_image(f->mlx.ptr, 800, 600);
	f->mlx.data = (int *)mlx_get_data_addr(f->mlx.img, &(f->mlx.bpp),
		&(f->mlx.size_line), &(f->mlx.endian));
	f->cre = 0.0;
	f->cim = 0.0;
	f->nre = 0.0;
	f->nim = 0.0;
	f->oldre = 0.0;
	f->oldim = 0.0;
	f->zoom = 1.0;
	f->m_x = 0.0;
	f->m_y = 0.0;
	f->max = 50;
	f->p.x = 0;
	f->p.y = 0;
}

void	ft_init_bship(t_frac *f)
{
	f->freeze = 'n';
	f->mlx.ptr = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.ptr, 800, 600, "fractol");
	f->mlx.img = mlx_new_image(f->mlx.ptr, 800, 600);
	f->mlx.data = (int *)mlx_get_data_addr(f->mlx.img, &(f->mlx.bpp),
		&(f->mlx.size_line), &(f->mlx.endian));
	f->cre = 0.0;
	f->cim = 0.0;
	f->nre = 0.0;
	f->nim = 0.0;
	f->oldre = 0.0;
	f->oldim = 0.0;
	f->zoom = 1.0;
	f->m_x = 0.0;
	f->m_y = 0.0;
	f->max = 50;
	f->p.x = 0;
	f->p.y = 0;
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
		exit(1);
	else
		exit(1);
	key++;
	return (0);
}
