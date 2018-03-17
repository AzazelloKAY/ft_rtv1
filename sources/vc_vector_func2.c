/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vc_vector_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:33:09 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/17 21:18:28 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

//t_vec		vec_add(t_vec *a, t_vec *b)
//{
//	t_vec res;
//
//	res.a = point_add(a->a, b->a);
//	res.b = point_add(a->b, b->b);
//	return (res);
//}
//
//t_vec		vec_sub(t_vec *a, t_vec *b)
//{
//	t_vec res;
//
//	res.a = point_sub(a->a, b->a);
//	res.b = point_sub(a->b, b->b);
//	return (res);
//}

t_vec		*v_new(t_vec *v)
{
	t_vec *res;
	if (!(res = ft_memalloc(sizeof(t_vec))))
		return (NULL);
	if (v != NULL)
	{
		res->x = v->x;
		res->y = v->y;
		res->z = v->z;
	}
	return (res);
}

double 		v_len(t_vec a, t_vec b)
{
	double	res;
	t_vec	t;

	t.x = (b.x - a.x);
	t.y = (b.y - a.y);
	t.z = (b.z - a.z);
	res = sqrt((t.x * t.x) + (t.y * t.y) + (t.z * t.z));
	return (res);
}

t_vec		v_normalise(t_vec a)
{
	t_vec	res;
	double	len;

	len = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	res.x = a.x / len;
	res.y = a.y / len;
	res.z = a.z / len;
	return (res);
}

double		quad_equ_des(double a, double b, double c)
{
	return ((b * b) - (4 * a * c));
}

t_vec2		quad_equ(double a, double b, double c)
{
	double	d;
	t_vec2	res;

	d = quad_equ_des(a, b, c);
	if (d < 0)
	{
		res.x = NAN;
		res.y = NAN;
	}
	else
	{
		res.x = (-b + sqrt(d)) / (2 * a);
		res.y = (-b - sqrt(d)) / (2 * a);
	}
	return (res);
}
