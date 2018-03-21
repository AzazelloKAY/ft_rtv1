/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:46:57 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/21 20:36:18 by akokoshk         ###   ########.fr       */
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
	void	*objp;
	int		(*intersect)(t_ray *r,  void *obj, void *res);
	t_color	colr;

}					t_obj;

typedef struct		s_objarr
{
	int		objnum;
	t_obj	*obj;
}					t_objarr;

/*
*** rt_sphere.c
*/

int					rt_sphere_intersect(t_ray *r, void *obj, void *res);
t_sphere			*rt_new_sphere(double x, double y, double z, double r);

//TEST
//void 	test_rtv1(t_obj *o);

/*
** rt_screen_trace.c
*/

void				rt_calc_scren(t_win	*w, t_cam *c, t_objarr *o);

/*
*** rt_obj.c
*/
t_objarr			*rt_new_obj_arr(int num);

#endif
