/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vc_vector_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:33:09 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/26 19:49:56 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/*
*** vector a-b len == v_sub(b, a)
*/

double		v_len1(t_vec a)
{
	double	res;

	res = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
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

double		quad_equ_d(double a, double b, double c)
{
	return ((b * b) - (4 * a * c));
}

int			v_quad_equ(double a, double b, double c, t_xy *res)
{
	double	d;
	t_xy	re;

	d = quad_equ_d(a, b, c);
	if (d < 0 || a < 0)
		return (0);
	re.x = (-b + sqrt(d)) / (2.0 * a);
	re.y = (-b - sqrt(d)) / (2.0 * a);
	if (res != NULL)
		*res = re;
	return (1);
}
