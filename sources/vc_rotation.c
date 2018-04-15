/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vc_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:29:32 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 15:59:42 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec			rotate_vec(t_vec v, t_vec rad)
{
    t_vec res;

    res.x = (((v.x * cos(rad.y)) - (((v.z * cos(rad.x)) -
            (v.y * sin(rad.x))) * sin(rad.y))) * cos(rad.z)) +
            (((v.y * cos(rad.x)) + (v.z * sin(rad.x))) * sin(rad.z));

    res.y = (((v.y * cos(rad.x)) + (v.z * sin(rad.x))) * cos(rad.z)) -
            (((v.x * cos(rad.y)) - (((v.z * cos(rad.x)) -
                    (v.y * sin(rad.x))) * sin(rad.y))) * sin(rad.z));

    res.z = (((v.z * cos(rad.x)) - (v.y * sin(rad.x))) *
            cos(rad.y)) + (v.x * sin(rad.y));

    return (res);
}

t_vec			calc_radians(t_vec angle)
{
    t_vec rad;

    rad.x = M_PI * angle.x / 180;
    rad.y = M_PI * angle.y / 180;
    rad.z = M_PI * angle.z / 180;
    return (rad);
}
