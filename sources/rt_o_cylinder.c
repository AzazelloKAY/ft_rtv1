/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_o_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:17:56 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/22 21:17:56 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_xy		rt_cylindr_intersect(t_ray *r, void *obj)
{
	t_cylinder	*cy;
	t_xy		res;
	t_vec		abc;
	double		tprod;
	t_vec		len;

	res.x = -1;
	res.y = -1;
	cy = (t_cylinder*)obj;
	tprod = v_dotprod(r->dir, cy->v);
	abc.x = v_dotprod(r->dir, r->dir) - (tprod * tprod);
	len = v_sub(r->or, cy->c);
	abc.y = 2 * (v_dotprod(r->dir, len) - (tprod * v_dotprod(len, cy->v)));
	tprod = v_dotprod(len, cy->v);
	abc.z = v_dotprod(len, len) - (tprod * tprod) - (cy->rad * cy->rad);
	v_quad_equ(abc.x, abc.y, abc.z, &res);
	return (res);
}

t_cylinder	*rt_new_cylindr(double xyz[3], double rad, t_vec v, double mxm)
{
    t_cylinder *cy;

    if (!(cy = ft_memalloc(sizeof(t_cylinder))))
        return (NULL);
    cy->c.x = xyz[0];
    cy->c.y = xyz[1];
    cy->c.z = xyz[2];
    cy->rad = rad;
    cy->v = v_normalise(v);
	cy->maxm = mxm;
    return (cy);
}

void 		rt_cylindr_obj(t_obj *o, t_cylinder *cy, uint32_t colr)
{
	o->colr.val = colr;
	o->intersect = rt_cylindr_intersect;
	o->objp = cy;
}
