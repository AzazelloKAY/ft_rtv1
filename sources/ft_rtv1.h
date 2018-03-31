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

typedef struct 	s_sphere
{
	t_vec	centr;
	double	radius;
}				t_sphere;

typedef struct 	s_plane
{
	t_vec	o;
	t_vec	n;
}				t_plane;

typedef struct 	s_cylinder
{
	t_vec	c;
	t_vec	v;
	double	rad;
	double	maxm;
}				t_cylinder;

typedef struct 	s_cone
{
	t_vec	c;
	t_vec	v;
	double	k;
	double	minm;
	double	maxm;

}				t_cone;

typedef struct 	s_light
{
	t_vec	cntr;
	t_color	colr;
	double	fading;
}				t_light;

typedef struct	s_obj
{
	void	*objp;
    t_xy	(*intersect)(t_ray *r,  void *obj);
	t_color	colr;

}				t_obj;

typedef struct	s_scene
{
	int		objnum;
	t_obj	*obj;
	int		lnum;
	t_light	*light;
}				t_scene;

/*
*** rt_sphere.c
*/

t_xy			rt_sphere_intersect(t_ray *r, void *obj);
t_sphere		*rt_new_sphr(double x, double y, double z, double rad);
void 			rt_sphr_obj(t_obj *o, t_sphere *s, uint32_t colr);

/*
*** rt_o_plane.c
*/

t_xy			rt_plane_intersect(t_ray *r, void *obj);
t_plane			*rt_new_plane(double x, double y, double z, t_vec n);
void			rt_plane_obj(t_obj *o, t_plane *p, uint32_t colr);

/*
*** rt_o_cylinder.c
*/

t_xy			rt_cylindr_intersect(t_ray *r, void *obj);
t_cylinder  	*rt_new_cylindr(double xyz[3], double rad, t_vec v, double mxm);
void 			rt_cylindr_obj(t_obj *o, t_cylinder *cy, uint32_t colr);

/*
*** rt_o_cone.c
*/

t_xy			rt_cone_intersect(t_ray *r, void *obj);
t_cone			*rt_new_cone(double xyz[3], t_vec v, double k_minm_maxm[3]);
void			rt_cone_obj(t_obj *o, t_cone *co, uint32_t colr);

/*
*** rt_screen_trace.c
*/

void			rt_calc_scren(t_win	*w, t_cam *c, t_scene *o);

/*
*** rt_obj.c
*/
t_scene		*rt_new_obj_arr(int onum, int lnum);

#endif
