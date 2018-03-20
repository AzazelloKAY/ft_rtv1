/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vc_cam_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:39:07 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/20 22:13:27 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_cam	*cam_new(double x, double y, double z)
{
	t_cam	*c;

	if (!(c = ft_memalloc(sizeof(t_cam))))
		return (NULL);
	c->orig.x = x;
	c->orig.y = y;
	c->orig.z = z;
	c->fov = 70;
	c->vh = 1;
	c->vw = 1;
	c->tmin = 0;
	c->tmax = INFINITY;

	return (c);
}

t_vec	vc_prim_ray(t_cam *c, int x, int y, t_vec img)
{
	t_vec	vDir;
	t_vec	tmp;
	double	tana2;

	//img.z = (double)imageWidth / (double)imageHeight; // assuming width > height
	//img.x == WINWIDTH
	//img.y == WINHEIGHT

	//fov = field of view in degrees 60*
	tana2 = tan(c->fov / 2 * M_PI / 180);
	tmp.x = (2 * ((x + 0.5) / img.x) - 1) * tana2 * img.z;
	tmp.y = (1 - 2 * ((y + 0.5) / img.y)) * tana2;
	tmp.z = -1;
	vDir = v_sub(tmp, c->orig); // note that this just equal to Vec3f(Px, Py, -1);
	vDir = v_normalise(vDir); // it's a direction so don't forget to normalize
	return (vDir);
}

///*
//*** viewpoint
//*/
//
//t_vec	vc_vp_ray(int x, int y, int z)
//{
//	t_vec v;
//	double vy;
//
//	v.x = x * (c->vw / img.x);
//	v.y = y * (c->vh / img.y);
//	v.z = z;
//}



