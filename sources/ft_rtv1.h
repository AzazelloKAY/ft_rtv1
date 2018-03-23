/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:46:57 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/23 21:57:06 by akokoshk         ###   ########.fr       */
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

typedef struct 		s_plane
{
	t_vec	c;
	t_vec	n;
}					t_plane;

typedef struct 		s_cylinder
{
	t_vec	c;
	t_vec	v;
	double	radius;
	double	len; //maxm
}					t_cylinder;

typedef struct 		s_cone
{
	t_vec	c;
	t_vec	v;
	double	k;
	double	minm;
	double	maxm;

}					t_cone;

typedef struct 		s_light
{
	t_vec	centr;
	t_color	colr;
}					t_light;

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
t_sphere			*rt_new_sphr(double x, double y, double z, double r);
void 				rt_sphr_obj(t_obj *o, t_vec cntr, double r, uint32_t colr);

/*
*** rt_o_plane.c
*/

int					rt_plane_intersect(t_ray *r, void *obj, void *res);
t_plane				*rt_new_plane(double x, double y, double z, t_vec n);
//void 				rt_plane_obj(t_obj *o, t_vec c, t_vec n, uint32_t colr);

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
