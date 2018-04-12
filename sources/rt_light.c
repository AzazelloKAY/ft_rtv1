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


static double	rt_get_l_diffusion(t_ray ray)
{

}

double			rt_get_l_intensity(t_ray ray, t_light *l, t_scene *s, t_vec norm)
{
	t_rtres	rt;
	t_vec	len;
	double	res;
	double	diff;

	res = 0.0;

	len = v_sub(l->cntr, ray.or);
	ray.dir = v_normalise(len);
	if (!ray_trace(&ray, s, &rt, v_len1(len)))
		res += l->intens;

	diff = v_dotprod(norm, ray.dir);
	res = (diff >= 0) ? diff * res : 0;
	return (res);
}

//get_color ?????????????????????????
double			rt_calc_light(t_ray ray, t_scene *s, t_rtres rtres)
{
	double	res;
	int		i;
	t_vec	normale;

	if (rtres.t.x < 0)
		return (s->minlight);
	ray.or = v_add(ray.or, v_mul_scal(ray.dir, rtres.t.x - 0.0001));

	normale = rtres.obj->getnormal(ray.or, rtres.obj->objp);


	//res = rt_get_l_intensity(ray, s, rtres.t.x);

	i = 0;
	while (i < s->lnum)
	{
		if (s->light[i].type == e_point)
		{

			res += rt_get_l_intensity(ray, &s->light[i], s, normale);
		}
		else if (s->light[i].type == e_ambient)
			res += s->light[i].intens;
		i++;
	}

	return (res);
}
