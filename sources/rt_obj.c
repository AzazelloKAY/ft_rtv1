/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:32:56 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/20 21:55:32 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_obj	*rt_obj_new(int num)
{
	t_obj	*o;

	if (num < 1)
		return (NULL);
	if (!(o = ft_memalloc(sizeof(t_obj) * num)))
		return (NULL);
	return (o);
}

