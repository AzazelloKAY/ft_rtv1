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


t_xy		rt_plane_intersect(t_ray *r, void *obj)
{
	t_plane		*p;
    t_xy		ab;
    t_xy		res;

	p = (t_plane*)obj;
    res.x = -1;
    res.y = -1;
//	a = v_dotprod(v_sub(p->o, r->a), p->n); //праволево
//	b = v_dotprod(r->b, p->n);

	ab.x = v_dotprod(p->n, v_sub(r->a, p->o));
	ab.y = v_dotprod(p->n, r->b);

	if (ab.y == 0)
		return (res);
    res.x = -ab.x / ab.y;
    res.y = res.x;

	return (res);
}

t_plane		*rt_new_plane(double x, double y, double z, t_vec n)
{
	t_plane *p;

	if (!(p = ft_memalloc(sizeof(t_plane))))
		return (NULL);
	p->o.x = x;
	p->o.y = y;
	p->o.z = z;
	p->n = v_normalise(n);
	return (p);
}

void        rt_plane_obj(t_obj *o, t_plane *p, uint32_t colr)
{
	o->colr.val = colr;
	o->intersect = rt_plane_intersect;
	o->objp = p;
}
