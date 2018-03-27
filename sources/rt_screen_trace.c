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
	t_vec v;

	v.x = point.x * (c->vw / i->w);
	v.y = point.y * (c->vh / i->h);
	v.z = point.z;
	return (v);
}

static t_color		ray_trace(t_ray *r, t_objarr *o)
{
	t_color	c;
	int 	i;
    t_xy	t;
	double	closest_t;
	t_obj	*closest_o;

	c.val = 0;
	closest_t = INFINITY;
	closest_o = NULL;
	i = o->objnum;
	while (i--)
	{
        t = o->obj[i].intersect(r, o->obj[i].objp);
		if (t.x < 0 && t.y < 0)
			continue ;
		if (t.x >= 0 && t.x < closest_t)
		{
			closest_t = t.x;
			closest_o = &o->obj[i];
		}
        if (t.y >= 0 && t.y < closest_t)
        {
            closest_t = t.y;
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

			ray.dir = v_sub(ray.dir, c->orig);	//?
			ray.dir = v_normalise(ray.dir);		//?

			p.colr = ray_trace(&ray, o);

			ft_pixtoimg_shift(&w->img, &p);
			p.x++;
		}
		p.y--;
	}
}
