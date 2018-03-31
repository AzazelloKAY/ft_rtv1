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

static t_rtres		ray_trace(t_ray *r, t_scene *o)
{
	int 	i;
	double	closest_t;
	t_rtres	rt;
	t_obj	*closest_o;

	rt.colr.val = 0;
	closest_t = INFINITY;
	closest_o = NULL;
	i = o->objnum;
	while (i--)
	{
        rt.t = o->obj[i].intersect(r, o->obj[i].objp);
		if (rt.t.x < 0 && rt.t.y < 0)
			continue ;
		if (rt.t.x >= 0 && rt.t.x <= closest_t)
		{
			closest_t = rt.t.x;
			closest_o = &o->obj[i];
		}
        if (rt.t.y >= 0 && rt.t.y <= closest_t)
        {
            closest_t = rt.t.y;
            closest_o = &o->obj[i];
        }
	}
	((closest_o != NULL) ? (rt.colr.val = closest_o->colr.val) : 0);
	return (rt);
}

void				rt_calc_scren(t_win	*w, t_cam *c, t_scene *o)
{
	t_point	p;
	t_rtres	rtres;
	t_ray	ray;

	ray.or = c->orig;
	p.y = w->img.maxh;
	while (p.y > w->img.minh)
	{
		p.x = w->img.minw;
		while (p.x < w->img.maxw)
		{
			ray.dir.x = p.x;
			ray.dir.y = p.y;
			ray.dir.z = c->orig.z + 1;		//distance to camera // calculate it
			ray.dir = canv_to_vp(ray.dir, &w->img, c);

			rtres = ray_trace(&ray, o);
			p.colr = rtres.colr;
			//calculate light intensity thru every object on scene to every light source
			//ray.or = c->orig + t * ray.dir;
			//ray.dir = every light sourse point

			ft_pixtoimg_shift(&w->img, &p);
			p.x++;
		}
		p.y--;
	}
}
