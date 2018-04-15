/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:32:56 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 17:03:05 by akokoshk         ###   ########.fr       */
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

t_scene				*rt_new_scene(int onum, int lnum)
{
	t_scene	*scene;

	if (onum < 1)
		return (NULL);
	if (!(scene = ft_memalloc(sizeof(t_scene))))
		return (NULL);
	scene->objnum = onum;
	scene->obj = rt_new_obj(onum);
	scene->minlight = 0.0;
	scene->w = NULL;
	scene->cam = NULL;
	if (lnum > 0)
	{
		scene->lnum = lnum;
		scene->light = rt_new_light(lnum);
		scene->minlight = 1.0;
	}
	return (scene);
}

void				rt_set_ambi_light(t_light *l, double i)
{
	l->type = e_ambient;
	l->cntr.x = 0;
	l->cntr.y = 0;
	l->cntr.z = 0;
	l->colr.val = 0xFFFFFF;
	l->intens = i;
	l->fading = 0;
}

void				rt_set_point_light(t_light *l, double xyz[3], double i, double f)
{
	l->type = e_point;
	l->cntr.x = xyz[0];
	l->cntr.y = xyz[1];
	l->cntr.z = xyz[2];
	l->colr.val = 0xFFFFFF;
	l->intens = i;
	l->fading = f;
}
