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

static t_obj		*rt_new_obj(int onum)
{
	t_obj	*o;

	if (onum < 1)
		return (NULL);
	if (!(o = ft_memalloc(sizeof(t_obj) * onum)))
		return (NULL);
	return (o);
}

static t_light		*rt_new_light(int lnum)
{
	t_light	*l;

	if (lnum < 1)
		return (NULL);
	if (!(l = ft_memalloc(sizeof(t_light) * lnum)))
		return (NULL);
	return (l);
}

t_scene				*rt_new_obj_arr(int onum, int lnum)
{
	t_scene	*scene;

	if (onum < 1)
		return (NULL);
	if (!(scene = ft_memalloc(sizeof(t_scene))))
		return (NULL);
	scene->objnum = onum;
	scene->obj = rt_new_obj(onum);
	if (lnum > 0)
	{
		scene->lnum = lnum;
		scene->light = rt_new_light(lnum);
	}
	return (scene);
}

