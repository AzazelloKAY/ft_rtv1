/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vc_cam_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:39:07 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 17:45:37 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_cam	*cam_new(double x, double y, double z, double fov)
{
	t_cam	*c;

	if (!(c = ft_memalloc(sizeof(t_cam))))
		return (NULL);
	c->orig.x = x;
	c->orig.y = y;
	c->orig.z = z;
	c->dir.x = 0;
	c->dir.y = 0;
	c->dir.z = 1;
	c->dir = v_normalise(c->dir);
	c->fov = tan(((fov / 2) * M_PI) / 180);
	c->vph = 1;
	c->vpw = 1;
	c->tmin = 0;
	c->tmax = INFINITY;
	return (c);
}
