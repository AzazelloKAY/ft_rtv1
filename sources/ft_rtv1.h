/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:46:57 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/20 21:42:07 by akokoshk         ###   ########.fr       */
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
	double	(*intersect)(t_ray *r,  void *obj);
	t_color	colr;

}					t_obj;

/*
*** rt_sphere.c
*/

double		rt_sphere_intersect(t_ray *r, void *obj);
t_sphere	*rt_new_sphere(double x, double y, double z, double r);

//TEST
void 	test_rtv1(t_obj *o);


/*
*** rt_obj.c
*/
t_obj		*rt_obj_new(int num);

#endif
