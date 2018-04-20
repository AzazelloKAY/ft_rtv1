/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_o_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:18:03 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/26 19:45:22 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"


t_xy		rt_plane_intersect(t_ray r, void *obj)
{
	t_plane		*p;
    t_xy		ab;
    t_xy		res;

    res.x = -1;
    res.y = -1;
	p = (t_plane*)obj;
	ab.y = v_dotprod(p->n, r.dir);
	if (ab.y >= 0.00000000000001)
	{
		ab.x = v_dotprod(p->n, v_sub(r.or, p->o));
		res.x = -ab.x / ab.y;
		res.y = res.x;
	}
	return (res);
}

t_vec		rt_plane_normal(t_vec dot, void *obj)
{
	t_plane		*p;

	p = (t_plane*)obj;
	if (v_dotprod(p->n, dot) > 0)
		return (v_mul_scal(p->n, -1));
	return (p->n);
}

t_plane		*rt_new_plane(double xyz[3], t_vec n)
{
	t_plane *p;

	if (!(p = ft_memalloc(sizeof(t_plane))))
		return (NULL);
	p->o.x = xyz[0];
	p->o.y = xyz[1];
	p->o.z = xyz[2];
	p->n = v_normalise(n);
	return (p);
}

void        rt_plane_obj(t_obj *o, t_plane *p, uint32_t colr)
{
	o->colr.val = colr;
	o->intersect = rt_plane_intersect;
	o->getnormal = rt_plane_normal;
	o->objp = p;
	o->shine = 2.0;
}
