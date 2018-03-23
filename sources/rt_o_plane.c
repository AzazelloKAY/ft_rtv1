/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_o_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:18:03 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/23 21:45:14 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"


int			rt_plane_intersect(t_ray *r, void *obj, void *res)
{
	t_plane		*p;
	double		numerator;
	double		denominator;
	double		t;

	p = (t_plane*)obj;
//	numerator = v_mul_s(v_sub(p->c, r->a), p->n);
//	denominator = v_mul_s(r->b, p->n);

	numerator = v_mul_s(p->n, r->b) - v_mul_s(p->n, p->c);
	denominator = v_mul_s(p->n, r->b);

	if (denominator < 0)
		return (0);
	t = -numerator / denominator;
	*(double*)res = t;
	if (t < 0)
		return (0);
	else
		return (1);
}

t_plane		*rt_new_plane(double x, double y, double z, t_vec n)
{
	t_plane *p;

	if (!(p = ft_memalloc(sizeof(t_plane))))
		return (NULL);
	p->c.x = x;
	p->c.y = y;
	p->c.z = z;
	p->n = v_sub(n, p->c);
	p->n = v_normalise(p->n);
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