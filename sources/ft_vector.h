/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:09:32 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 15:59:45 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <math.h>
# include "../libft/libft.h"

typedef	struct		s_xy
{
	double x;
	double y;
}					t_xy;

typedef	struct		s_vec
{
	double x;
	double y;
	double z;
}					t_vec;

typedef struct		s_ray
{
	t_vec or;
	t_vec dir;
}					t_ray;

typedef struct		s_cam
{
	t_vec	orig;
	t_vec	dir;
	t_vec	ang;
	t_vec	rad;
	double	fov;
	double	vph;
	double	vpw;
	double	tmin;
	double	tmax;

}					t_cam;

/*
** vc_vector_func1.c
*/

t_vec				v_add(t_vec a, t_vec b);
t_vec				v_sub(t_vec a, t_vec b);
double				v_dotprod(t_vec a, t_vec b);
t_vec				v_mul_v(t_vec a, t_vec b);
t_vec				v_mul_scal(t_vec a, double b);

/*
** vc_vector_func2.c
*/

double 				v_len1(t_vec a);
t_vec				v_normalise(t_vec a);
double				quad_equ_d(double a, double b, double c);
int					v_quad_equ(double a, double b, double c, t_xy *res);

/*
*** vc_cam_code.c
*/

t_cam				*cam_new(double x, double y, double z, double fov);

/*
*** vc_rotation.c
*/

t_vec				rotate_vec(t_vec v, t_vec rad);
t_vec				calc_radians(t_vec angle);

#endif
