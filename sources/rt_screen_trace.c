/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_screen_trace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:11:50 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/23 21:08:34 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static t_vec		canv_to_vp(t_vec point, t_img *i, t_cam *c)
{
	t_vec v;

	v.x = point.x * (c->vw / i->w);
	v.y = point.y * (c->vh / i->h);
	v.z = point.z;
	return (v);
}

static t_color		ray_trace(t_ray *r, t_objarr *o)
{
	t_color	c;
	double	closest_t;
	t_obj	*closest_o;
	t_vec2	qres;
	int 	i;

	c.val = 0;
	closest_t = INFINITY;
	closest_o = NULL;
	i = o->objnum;
	while (i--)
	{
		if (o->obj[i].intersect(r, o->obj[i].objp, &qres) == 0)
			continue ;
		if (qres.x >= 0 && qres.x < closest_t)
		{
			closest_t = qres.x;
			closest_o = &o->obj[i];
		}
		if (qres.y >= 0 && qres.y < closest_t)
		{
			closest_t = qres.y;
			closest_o = &o->obj[i];
		}
	}
	((closest_o != NULL) ? (c.val = closest_o->colr.val) : 0);
	return (c);
}

void				rt_calc_scren(t_win	*w, t_cam *c, t_objarr *o)
{
	t_point	p;
	t_ray	ray;

	ray.a = c->orig;
	p.y = w->img.maxh;
	while (p.y > w->img.minh)
	{


		p.x = w->img.minw;
		while (p.x < w->img.maxw)
		{
			ray.b.x = p.x;
			ray.b.y = p.y;
			ray.b.z = c->orig.z + 1;		//distance to camera // calculate it
			ray.b = canv_to_vp(ray.b, &w->img, c);

			ray.b = v_sub(ray.b, c->orig);	//?
			ray.b = v_normalise(ray.b);		//?

			p.colr = ray_trace(&ray, o);

			ft_pixtoimg_shift(&w->img, &p);
			p.x++;
		}
		p.y--;
	}
}
