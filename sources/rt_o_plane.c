/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_o_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:18:03 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/22 21:18:07 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"


/*
 *
 * Plane

Definition:
 C is a point that lies on the plane
 V is the plane normal (unit length)

To hit a plane we notice that:

    (P-C)|V = 0
This means that the P-C vector is perpendicular to the normal, which is true when the point P lies on the plane.
Solution:

   (D*t+X)|V = 0
   D|V*t = -X|V
   t = -X|V / D|V
Before the division we should check whether D|V is nonzero. We can also check if the signs of D|V and X|V are different (if not, resulting t will be negative).
Surface normal vector at point P equals to the plane normal, unless D|V is negative, in which case N=-V.
 *
 *
 */