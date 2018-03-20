/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:09:32 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/20 20:56:21 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <math.h>
# include "../libft/libft.h"

typedef	struct		s_vec2
{
	double x;
	double y;
}					t_vec2;

typedef	struct		s_vec
{
	double x;
	double y;
	double z;
}					t_vec;

typedef struct		s_ray
{
	t_vec a;
	t_vec b;
}					t_ray;

typedef struct		s_cam
{
	t_vec	orig;
	t_vec	angle;
	double	fov;
	double	vh;
	double	vw;
	double	tmin;
	double	tmax;

}					t_cam;

/*
** vc_vector_func1.c
*/

t_vec		v_add(t_vec a, t_vec b);
t_vec		v_sub(t_vec a, t_vec b);
double		v_mul_s(t_vec a, t_vec b);
t_vec		v_mul_v(t_vec a, t_vec b);
t_vec		v_mul_scal(t_vec a, double b);

/*
** vc_vector_func2.c
*/

double 		v_len(t_vec a, t_vec b);
t_vec		v_normalise(t_vec a);
double		quad_equ_d(double a, double b, double c);
double		v_quad_equ(double a, double b, double c, t_vec2 *res);


/*
*** vc_cam_code.c
*/

t_cam		*cam_new(double x, double y, double z);

#endif
