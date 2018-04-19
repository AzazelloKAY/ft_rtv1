/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:46:57 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 17:27:42 by akokoshk         ###   ########.fr       */
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

typedef enum	e_lighttype
{
	e_ambient = 0,
	e_point = 1,
	e_directional = 2,

}				t_lighttype;

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
	t_lighttype	type;
	t_vec		cntr;
	t_color		colr;
	double		intens;
	double		fading;
	t_vec		dir;
}				t_light;

typedef struct	s_obj
{
	void	*objp;
    t_xy	(*intersect)(t_ray r,  void *obj);
	t_vec	(*getnormal)(t_vec dot, void *obj);
	t_color	colr;
	double	shine;

}				t_obj;

typedef struct	s_scene
{
	int		objnum;
	t_obj	*obj;
	int		lnum;
	t_light	*light;
	double	minlight;
	t_cam	*cam;
	t_win	*w;
}				t_scene;

typedef struct	s_rtres
{
	t_xy	t;
	t_color	colr;
	t_obj	*obj;
}				t_rtres;

/*
*** rt_sphere.c
*/

t_xy			rt_sphere_intersect(t_ray r, void *obj);
t_sphere		*rt_new_sphr(double xyz[3], double rad);
void 			rt_sphr_obj(t_obj *o, t_sphere *s, uint32_t colr);

/*
*** rt_o_plane.c
*/

t_xy			rt_plane_intersect(t_ray r, void *obj);
t_plane			*rt_new_plane(double xyz[3], t_vec n);
void			rt_plane_obj(t_obj *o, t_plane *p, uint32_t colr);

/*
*** rt_o_cylinder.c
*/

t_xy			rt_cylindr_intersect(t_ray r, void *obj);
t_cylinder  	*rt_new_cylindr(double xyz[3], double rad, t_vec v, double mxm);
void 			rt_cylindr_obj(t_obj *o, t_cylinder *cy, uint32_t colr);

/*
*** rt_o_cone.c
*/

t_xy			rt_cone_intersect(t_ray r, void *obj);
t_cone			*rt_new_cone(double xyz[3], t_vec v, double k_minm_maxm[3]);
void			rt_cone_obj(t_obj *o, t_cone *co, uint32_t colr);

/*
*** rt_screen_trace.c
*/

int				ray_trace(t_ray r, t_scene *s, t_rtres *rt, double tlim);
void			rt_calc_scren(t_win	*w, t_cam *c, t_scene *o);

/*
*** rt_obj.c
*/

t_scene			*rt_new_scene(int onum, int lnum);
void			rt_set_ambi_light(t_light *l, double i);
void			rt_set_point_light(t_light *l, double xyz[3], double i, double f);

/*
*** rt_light.c
*/

//double			rt_get_l_intensity(t_ray r, t_scene *s, double t);
uint32_t		rt_calc_light(t_ray ray, t_scene *s, t_rtres rtres);

/*
***
*/

double			f_get_smalest(t_xy *t);

/*
*** ft_img_keyhook.c
*/

void			ft_keyhookloop(t_scene *sc);

/*
*** main
*/

void			rt_redraw(t_scene *sc);

#endif
