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


t_xy      rt_sphere_intersect(t_ray r, void *obj)
{
	t_sphere	*s;
	t_vec		abc;
	t_vec		len;
	t_xy		qres;

    qres.x = -1;
    qres.y = -1;
	s = (t_sphere*)obj;
	abc.x = v_dotprod(r.dir, r.dir);
	len = v_sub(r.or, s->centr);
	abc.y = 2.0 * v_dotprod(r.dir, len);
	abc.z = v_dotprod(len, len) - (s->radius * s->radius);
	v_quad_equ(abc.x, abc.y, abc.z, &qres);
	return (qres);
}

t_vec		rt_sphere_normal(t_vec dot, void *obj)
{
	t_sphere	*s;
	t_vec		res;

	s = (t_sphere*)obj;
	res = v_normalise(v_sub(dot, s->centr));
	return (res);
}

t_sphere	*rt_new_sphr(double xyz[3], double rad)
{
	t_sphere *s;

	if (!(s = ft_memalloc(sizeof(t_sphere))))
		return (NULL);
	s->radius = rad;
	s->centr.x = xyz[0];
	s->centr.y = xyz[1];
	s->centr.z = xyz[2];
	return (s);
}

void 		rt_sphr_obj(t_obj *o, t_sphere *s, uint32_t colr)
{
    o->colr.val = colr;
    o->intersect = rt_sphere_intersect;
	o->getnormal = rt_sphere_normal;
    o->objp = s;
	o->shine = 2.0;
}

/*
 * точка пересечеия(удара луча O+tD) - центр сферы
 * обязательно нормализуем
 */




