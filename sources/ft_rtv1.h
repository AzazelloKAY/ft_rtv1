/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:46:57 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/18 16:56:11 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H

# include "../libft/libft.h"
# include "ft_vector.h"
# include "ft_img.h"
# include <stdio.h>
//# include <math.h>
# include <pthread.h>


//typedef double	t_vector __attribute__((vector_size(sizeof(double)*3)));


/*
** FT_RTv1 sources
*/

typedef struct 		s_sphere
{
	t_vec	centr;
	double	radius;
}					t_sphere;

typedef struct		s_obj
{
	void	*obj;
	//int (*test_intersect)(void *obj, t_point r_start, t_vec ray, t_point *cross_p);

}					t_obj;

/*
*** rt_sphere.c
*/

double		rt_sphere_intersect(t_ray *r, void *obj);

#endif
