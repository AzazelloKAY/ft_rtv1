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

t_point	*new_point(double y, double x, double z)
{
	t_point *p;

	if (!(p = ft_memalloc(sizeof(t_point))))
		return (NULL);
	p->y = y;
	p->x = x;
	p->z = z;
	return (p);
}

