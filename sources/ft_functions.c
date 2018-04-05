/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:19:24 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/15 21:22:26 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

double	f_get_smalest(t_xy *t)
{
	double res;
	double tmp;

	res = -1;
	if (t->x < 0 && t->y < 0)
		return (res);
	if ((res = t->x) < 0)
		res = t->y;
	else if (t->y >= 0 && t->y < res)
	{
		res = t->y; // Убить тмп заменить на рез
		tmp = t->y;
		t->y = t->x;
		t->x = tmp;
	}
	return (res);
}

