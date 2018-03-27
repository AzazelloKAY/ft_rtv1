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
	double		a;
	double		b;
    t_xy		res;

	p = (t_plane*)obj;
    res.x = -1;
    res.y = -1;
//	a = v_dotprod(v_sub(p->o, r->a), p->n); //праволево
//	b = v_dotprod(r->b, p->n);

	a = v_dotprod(p->n, v_sub(r->a, p->o));
	b = v_dotprod(p->n, r->b);

	if (b == 0)
		return (res);
    res.x = -a / b;
    res.y = res.x;
//printf(">>%10f\n", t);

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

void 		rt_plane_obj(t_obj *o, t_vec c, t_vec n, uint32_t colr)
{
	o->colr.val = colr;
	o->intersect = rt_plane_intersect;
	o->objp = rt_new_plane(c.x, c.y, c.z, n);
}

/*
 *
 * Plane

Definition:
 C is a point that lies on the plane
 V is the plane normal (unit length)

To hit a plane we notice that:

    (P-C)|V = 0
This means that the P-C vector is perpendicular to the normal, which is true when the point P lies on the plane.
Solution:

   (D*t+X)|V = 0
   D|V*t = -X|V
   t = -X|V / D|V
Before the division we should check whether D|V is nonzero. We can also check if the signs of D|V and X|V are different (if not, resulting t will be negative).
Surface normal vector at point P equals to the plane normal, unless D|V is negative, in which case N=-V.
 *
 *
 */