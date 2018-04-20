/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:15:05 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 18:13:38 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static double	rt_get_shine(t_vec view, t_vec light, t_vec norm, double sh)
{
	double	res;
	t_vec	refl;

	refl = v_mul_scal(v_mul_scal(norm, 2.0), v_dotprod(norm, light));
	refl = v_sub(refl, light);
	res = v_dotprod(refl, view);
	if (res >= 0)
		res = pow(res/(v_len1(refl) * v_len1(view)), sh);
	else
		res = 0.0;
	return (res);
}

static t_xy		get_lightintens(t_ray ray, t_light *l, t_scene *s, t_vec norm)
{
	t_rtres	rt;
	t_vec	l_dir;
	t_xy	res;
	double	diff;

	res.x = 0.0;
	res.y = 0.0;
	l_dir = v_sub(l->cntr, ray.or);
	ray.dir = v_normalise(l_dir);
	if (!ray_trace(ray, s, &rt, v_len1(l_dir)))
	{
		res.x += l->intens;
		res.y = rt_get_shine(v_sub(s->cam->orig, ray.or), ray.dir, norm, 80.0);
		diff = v_dotprod(norm, ray.dir);
		res.x *= (diff >= 0) ? diff : 0;
	}
	return (res);
}

uint32_t		rt_calc_light(t_ray ray, t_scene *s, t_rtres rtres)
{
	t_rtres		res;
	int			i;
	t_vec		normale;
	t_xy		dif_shin;

	if (rtres.t.x < 0)
		return (0);
	ray.or = v_add(ray.or, v_mul_scal(ray.dir, rtres.t.x - 0.000000001));
	normale = rtres.obj->getnormal(ray.or, rtres.obj->objp);
	i = 0;
	res.t.x = 0.0;
	res.colr.val = 0;
	while (i < s->lnum)
	{
		if (s->light[i].type == e_point)
		{
			dif_shin = get_lightintens(ray, &s->light[i], s, normale);
			res.t.x += dif_shin.x;
			res.colr.val = colr_add(res.colr.val, colr_scal(
				colr_scal(s->light[i].colr.val, dif_shin.y), dif_shin.x));
		}
		else if (s->light[i].type == e_ambient)
			res.t.x += s->light[i].intens;
		i++;
	}
	return (colr_add(colr_scal(rtres.obj->colr.val, res.t.x), res.colr.val));
}
