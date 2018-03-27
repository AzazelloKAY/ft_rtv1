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

//t_xy      rt_cylinder_intersect(t_ray *r, void *obj)
//{
//	t_cylinder	*cy;
//	t_xy		res;
//	t_vec		abc;
//
//	cy = (t_cylinder*)obj;
//	abc.x =
//
//	return (res);
//}

t_cylinder  *rt_new_cylinder(double xyz[3], double radius, t_vec v, double maxm)
{
    t_cylinder *cy;

    if (!(cy = ft_memalloc(sizeof(t_cylinder))))
        return (NULL);
    cy->c.x = xyz[0];
    cy->c.y = xyz[1];
    cy->c.z = xyz[2];
    cy->rad = radius;
    cy->v = v;
	cy->maxm = maxm;
    return (cy);
}

void 		rt_cylinder_obj(t_obj *o, t_cylinder *cy, uint32_t colr)
{
	o->colr.val = colr;
	//o->intersect = rt_cylinder_intersect;
	o->objp = cy;
}
