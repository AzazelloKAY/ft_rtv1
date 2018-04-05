/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_screen_trace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:11:50 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/26 19:29:27 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static t_vec		canv_to_vp(t_vec point, t_img *i, t_cam *c)
{
	t_vec	v;
	double	screnratio;

	screnratio = ((double)i->w / (double)i->h);
	v.x = point.x * (c->vpw / i->w) * screnratio * c->fov;
	v.y = point.y * (c->vph / i->h) * c->fov;
	v.z = point.z;


//	Matrix44f cameraToWorld;
//	cameraToWorld.set(...); // set matrix
//	Vec3f rayOriginWorld, rayPWorld;
//	cameraToWorld.multVectMatrix(rayOrigin, rayOriginWorld);
//	cameraToWorld.multVectMatrix(Vec3f(Px, Py, -1), rayPWorld);
//	Vec3f rayDirection = rayPWorld - rayOriginWorld;

	v = v_sub(v, c->orig);
	v = v_normalise(v);

	return (v);
}

/*
*** TODO remove double calculation of color for shadows RT
*/

int				ray_trace(t_ray *r, t_scene *s, t_rtres *rt, double tlim)
{
	int 	i;
	double	closest_t;
	t_xy	t;
	t_obj	*closest_o;

	closest_t = tlim;
	closest_o = NULL;
	i = s->objnum;
	while (i--)
	{
		t = s->obj[i].intersect(r, s->obj[i].objp);
		if (f_get_smalest(&t) < 0)
			continue;
		if (t.x < closest_t)
		{
			rt->t = t;
			closest_t = t.x;
			closest_o = &s->obj[i];
		}
	}
	rt->colr.val = (closest_o != NULL) ? closest_o->colr.val : 0;
	if (closest_o != NULL)
		return (1);
	return (0);
}

void				rt_calc_scren(t_win	*w, t_cam *c, t_scene *s)
{
	t_point	p;
	t_rtres	rtres;
	t_ray	ray;
	double	intens;

	ray.or = c->orig;
	p.y = w->img.maxh;
	ray.dir.z = c->orig.z + 1;		//distance to camera // calculate it
	while (p.y > w->img.minh)
	{
		p.x = w->img.minw;
		while (p.x < w->img.maxw)
		{
			ray.dir.x = p.x;
			ray.dir.y = p.y;
			ray.dir = canv_to_vp(ray.dir, &w->img, c);

			if (ray_trace(&ray, s, &rtres, INFINITY))
			{
				intens = rt_get_light_intensity(ray, s, rtres.t.x);

				//printf(">%6f\n", intens);

				rtres.colr.val = ft_colr_mul_scal(rtres.colr.val, intens);

			}
			p.colr.val = rtres.colr.val;

			//calculate light intensity thru every object on scene to every light source
			//ray.or = c->orig + t * ray.dir;
			//ray.dir = every light sourse point

			ft_pixtoimg_shift(&w->img, &p);
			p.x++;
		}
		p.y--;
	}
}
