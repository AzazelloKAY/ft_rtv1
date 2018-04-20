/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_screen_trace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:11:50 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 17:31:11 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static t_vec	cam_to_vp(t_point scren_point, t_img *i, t_cam *c)
{
	t_vec	view_dir;
	double	screnratio;

	screnratio = ((double)i->w / (double)i->h);
	view_dir.x = scren_point.x * (c->vpw / i->w) * screnratio * c->fov;
	view_dir.y = scren_point.y * (c->vph / i->h) * c->fov;
	view_dir.z = c->dir.z;
	view_dir = rotate_vec(view_dir, calc_radians(c->ang));
	return (v_normalise(view_dir));
}

static double	f_get_smalest(t_xy *t)
{
	double res;

	res = -1;
	if (t->x < 0 && t->y < 0)
		return (res);
	if ((res = t->x) < 0)
	{
		res = t->y;
		t->y = t->x;
		t->x = res;
	}
	else if (t->y >= 0 && t->y < res)
	{
		res = t->y;
		t->y = t->x;
		t->x = res;
	}
	return (res);
}

int				ray_trace(t_ray r, t_scene *s, t_rtres *rt, double tlim)
{
	int		i;
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
	rt->colr.val = 0;
	if ((rt->obj = closest_o) != NULL)
		return (1);
	return (0);
}

void			rt_calc_scren(t_win *w, t_cam *c, t_scene *s)
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
			ray.dir = cam_to_vp(p, &w->img, c);
			if (ray_trace(ray, s, &rtres, INFINITY))
				rtres.colr.val = rt_calc_light(ray, s, rtres);
			p.colr.val = rtres.colr.val;
			ft_pixtoimg_shift(&w->img, &p);
			p.x++;
		}
		p.y--;
	}
}
