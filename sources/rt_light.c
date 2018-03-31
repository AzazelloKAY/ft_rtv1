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

void	rt_new_light(t_light *l, double xyz[3], uint32_t c, uint32_t f)
{
	l->cntr.x = xyz[0];
	l->cntr.y = xyz[1];
	l->cntr.z = xyz[2];
	l->colr.val = c;
	l->fading.val = f;
}
