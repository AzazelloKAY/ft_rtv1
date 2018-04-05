/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:15:05 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/22 21:15:05 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void	rt_set_ambi_light(t_light *l, double i)
{
	l->type = e_ambient;
	l->cntr.x = 0;
	l->cntr.y = 0;
	l->cntr.z = 0;
	l->colr.val = 0xFFFFFF;
	l->intens = i;
	l->fading = 0;
}

void	rt_set_point_light(t_light *l, double xyz[3], double i, double f)
{
	l->type = e_point;
	l->cntr.x = xyz[0];
	l->cntr.y = xyz[1];
	l->cntr.z = xyz[2];
	l->colr.val = 0xFFFFFF;
	l->intens = i;
	l->fading = f;
}

double	rt_get_light_intensity(t_ray ray, t_scene *s, double t)
{
	t_rtres	rt;
	t_vec	len;
	double	res;
	int		i;

	res = (s->lnum > 0) ? 0 : 1;
	if (t < 0)
		return (res);
	ray.or = v_add(ray.or, v_mul_scal(ray.dir, t - 0.0001));
	i = 0;
	while (i < s->lnum)
	{
		if (s->light[i].type == e_point)
		{
			len = v_sub(s->light[i].cntr, ray.or);
			ray.dir = v_normalise(len);
			if (!ray_trace(&ray, s, &rt, v_len1(len)))
				res += s->light[i].intens;

		}
		else if (s->light[i].type == e_ambient)
			res += s->light[i].intens;
		i++;
	}
	return (res);
}
