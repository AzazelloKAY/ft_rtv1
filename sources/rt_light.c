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
	//int		i;

	res = 0.0;

	len = v_sub(l->cntr, ray.or);
	ray.dir = v_normalise(len);
	if (!ray_trace(&ray, s, &rt, v_len1(len)))
		res += l->intens;

	double tt = v_dotprod(norm, ray.dir);
	res = (tt >= 0) ? tt * res : 0;
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

	//************************************************************************************
	if (rtres.obj->getnormal != NULL)
		normale = rtres.obj->getnormal(ray.or, rtres.obj->objp);
	else
	{
		normale.x = 1;
		normale.y = 1;
		normale.z = 1;
	}
	//************************************************************************************

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


//double			rt_get_l_intensity(t_ray ray, t_scene *s, double t)
//{
//	t_rtres	rt;
//	t_vec	len;
//	double	res;
//	int		i;
//
//	res = 0.0;//(s->lnum > 0) ? 0 : 1;
////	if (t < 0)
////		return (res);
////	ray.or = v_add(ray.or, v_mul_scal(ray.dir, t - 0.0001));
//
//	i = 0;
//	while (i < s->lnum)
//	{
//		if (s->light[i].type == e_point)
//		{
//			len = v_sub(s->light[i].cntr, ray.or);
//			ray.dir = v_normalise(len);
//			if (!ray_trace(&ray, s, &rt, v_len1(len)))
//				res += s->light[i].intens;
//
//		}
//		else if (s->light[i].type == e_ambient)
//			res += s->light[i].intens;
//		i++;
//	}
//	return (res);
//}
//
////get_color ?????????????????????????
//double			rt_calc_light(t_ray ray, t_scene *s, t_rtres rtres)
//{
//	double res;
//
//	if (rtres.t.x < 0)
//		return (s->minlight);
//
//	ray.or = v_add(ray.or, v_mul_scal(ray.dir, rtres.t.x - 0.0001));
//	res = rt_get_l_intensity(ray, s, rtres.t.x);
//
//	return (res);
//}
