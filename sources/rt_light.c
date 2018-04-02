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

double	rt_get_light_intensity(t_ray r, t_scene *s, t_xy t)
{
	t_rtres	tt;
	double	res;
	int		i;

	res = 0;
	if ((tt.t.x = f_get_smalest(&t)) < 0)
		return (res);
	r.or = v_add(r.or, v_mul_scal(r.dir, tt.t.x));
	i = 0;
	while (i < s->lnum)
	{
		if (s->light[i].type == e_point)
		{
			r.dir = v_normalise(s->light[i].cntr);
			tt = ray_trace(&r, s);
			if (tt.t.x >= 0 || tt.t.y >= 0)
				res += s->light[i].intens;

		}
		else if (s->light[i].type == e_ambient)
			res += s->light[i].intens;
		i++;
	}
	((res > 1) ? res = 1 : 0);
	((res < 0) ? res = 0 : 0);
	return (res);
}
