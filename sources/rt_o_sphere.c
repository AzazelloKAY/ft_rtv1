/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_o_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:19:30 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/26 19:20:03 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"


t_xy      rt_sphere_intersect(t_ray *r, void *obj)
{
	t_sphere	*s;
	t_vec		abc;
	t_vec		len;
	t_xy		qres;

	s = (t_sphere*)obj;
	abc.x = v_dotprod(r->dir, r->dir);
	len = v_sub(r->or, s->centr);
	abc.y = 2.0 * v_dotprod(r->dir, len);
	abc.z = v_dotprod(len, len) - (s->radius * s->radius);
    qres.x = -1;
    qres.y = -1;
	v_quad_equ(abc.x, abc.y, abc.z, &qres);
	return (qres);
}

t_sphere	*rt_new_sphr(double x, double y, double z, double rad)
{
	t_sphere *s;

	if (!(s = ft_memalloc(sizeof(t_sphere))))
		return (NULL);
	s->radius = rad;
	s->centr.x = x;
	s->centr.y = y;
	s->centr.z = z;
	return (s);
}

void 		rt_sphr_obj(t_obj *o, t_sphere *s, uint32_t colr)
{
    o->colr.val = colr;
    o->intersect = rt_sphere_intersect;
    o->objp = s;
}

/*
 * точка пересечеия(удара луча O+tD) - центр сферы
 * обязательно нормализуем
 */




