/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_o_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:18:00 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/22 21:18:00 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_xy		rt_cone_intersect(t_ray *r, void *obj)
{
	t_cone		*co;
	t_xy		res;
	t_vec		abc;



	double		kk1;
	double		tt;
	t_vec		len;


	co = (t_cone*)obj;
	res.x = -1;
	res.y = -1;
	kk1 = 1 + (co->k * co->k);
	tt = v_dotprod(r->dir, co->v);
	abc.x = v_dotprod(r->dir, r->dir) - kk1 * (tt * tt);
	len = v_sub(r->or, co->c);
	abc.y = 2 * (v_dotprod(r->dir, len) - kk1 * (tt * v_dotprod(len, co->v)));
	tt = v_dotprod(len, co->v);
	abc.z = v_dotprod(len, len) - kk1 * (tt * tt);
	v_quad_equ(abc.x, abc.y, abc.z, &res);
	return (res);
}

t_vec		rt_cone_normal(t_vec dot, void *obj)
{
	t_cone		*c;
	t_vec		res;
	t_vec		v;
	double		len;

	c = (t_cone*)obj;
	res = v_sub(dot, c->c);
	len = v_dotprod(res, c->v);
	v = c->v;
	if (len < 0) //???????????????????
	{
		v = v_mul_scal(v, -1);
		len = -len;
	}
	v = v_mul_scal(v, len);
	v = v_mul_scal(v, 1 + (c->k * c->k));
	res = v_sub(res, v);


	return (v_normalise(res));
}

t_cone		*rt_new_cone(double xyz[3], t_vec v, double k_minm_maxm[3])
{
	t_cone *co;

	if (!(co = ft_memalloc(sizeof(t_cone))))
		return (NULL);
	co->c.x = xyz[0];
	co->c.y = xyz[1];
	co->c.z = xyz[2];
	co->v = v_normalise(v);
	co->k = tan(k_minm_maxm[0]);
	co->minm = k_minm_maxm[1];
	co->maxm = k_minm_maxm[2];
	return (co);
}

void		rt_cone_obj(t_obj *o, t_cone *co, uint32_t colr)
{
	o->colr.val = colr;
	o->intersect = rt_cone_intersect;
	o->getnormal = rt_cone_normal;
	o->objp = co;
	o->shine = 2.0;
}
