/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:32:56 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/21 20:27:50 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static t_obj		*rt_new_obj(int num)
{
	t_obj	*o;

	if (num < 1)
		return (NULL);
	if (!(o = ft_memalloc(sizeof(t_obj) * num)))
		return (NULL);
	return (o);
}

t_objarr			*rt_new_obj_arr(int num)
{
	t_objarr	*objarr;

	if (num < 1)
		return (NULL);
	if (!(objarr = ft_memalloc(sizeof(t_objarr))))
		return (NULL);
	objarr->objnum = num;
	objarr->obj = rt_new_obj(num);
	return (objarr);
}

