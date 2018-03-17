/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vc_vector_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:46:37 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/17 20:37:28 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec		v_add(t_vec a, t_vec b)
{
	t_vec res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec		v_sub(t_vec a, t_vec b)
{
	t_vec res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

double		v_mul_s(t_vec a, t_vec b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec		v_mul_v(t_vec a, t_vec b)
{
	t_vec res;

	res.x = (a.y * b.z) - (a.z * b.y);
	res.y = (a.z * b.x) - (a.x * b.z);
	res.z = (a.x * b.y) - (a.y * b.x);
	return (res);
}

t_vec		v_mul_scal(t_vec a, double b)
{
	t_vec res;

	res.x = a.x * b;
	res.y = a.y * b;
	res.z = a.z * b;
	return (res);
}

