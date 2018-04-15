/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:42:53 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/26 19:45:48 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void	print_v(t_vec *a)
{
	printf(">x=%10f y=%10f z=%10f\n", a->x, a->y, a->z);
}

/*
*** viewpoint
*/




int main()
{
	//test_rtv1(&o);

	t_scene		*o;
	t_win		*w;
	t_cam		*cam;

	w = ft_init_mlx("test rtv");
	ft_init_img(w);
	cam = cam_new(0, 0, -0.5, 95);

	o = rt_new_scene(6, 3);
	o->cam = cam;

	//AMBI LIGHT
	rt_set_ambi_light(&o->light[0], 0.18);
	//POINT LIGHT
	double		lxyz[3] = {50, 20, 600};//{-150.0, 150, 150};
	rt_set_point_light(&o->light[1], lxyz, 0.45, 0);
	o->light[1].colr.val = 0x0000ff;

	double		l2xyz[3] = {50, -200, -100};//{-150.0, 150, 150};
	rt_set_point_light(&o->light[2], l2xyz, 0.43, 0);
	o->light[2].colr.val = 0xFFFFff;

	//1
	double s1xyz[3] = {60, 0, 490};
	rt_sphr_obj(&o->obj[0], rt_new_sphr(s1xyz, 60), 0x00FF00);
	//2
	double s2xyz[3] = {-20, 0, 500};
	rt_sphr_obj(&o->obj[1], rt_new_sphr(s2xyz, 50), 0xFF0000);

	//3
	t_vec v;
	v.x = -100;
	v.y = 100;
	v.z = 0;
	double coxyz[3] = {20.0, -100.0, 540.0};
	double k_minm_maxm[3] = {10, 4.0, 200.0};
	rt_cone_obj(&o->obj[2], rt_new_cone(coxyz, v, k_minm_maxm), 0x254F21);


	//4
	t_vec n;
	n.x = 200;
	n.y = 100;
	n.z = 500;
	double cyxyz[3] = {-150.0, -100.0, 100.0};
	rt_cylindr_obj(&o->obj[3], rt_new_cylindr(cyxyz, 9.2, n, 1), 0x1234C6);

	//5
	n.x = 0;
	n.y = 1;
	n.z = 0;
	double pxyz[3] = {250.0, 250.0, 0.0};
	rt_plane_obj(&o->obj[4], rt_new_plane(pxyz, n), 0x00F0F0);

	//6
	n.x = 0;
	n.y = -1;
	n.z = 0;
	double p2xyz[3] = {250.0, -250.0, 0.0};
	rt_plane_obj(&o->obj[5], rt_new_plane(p2xyz, n), 0xF0C173);







	rt_calc_scren(w, o->cam, o);

	ft_drawimg(w);

	ft_keyhookloop(w, 0);
    //printf(">%10f %10f %10f", ss->b.x, ss->b.y, ss->b.z);
    return 0;
}




/*
 *
 * The equation for each of the 4 basic objects required in the RT subject is really simple when these objects
are placed at the center of the frame of reference:
X² + Y² + Z² = radius² for a sphere centered on (0,0,0).
If your sphere is located somewhere else, the equation is more complex:
(X - center_X)² + (Y - center_Y)² + (Z - center_Z)² = radius²
As soon as you manipulate this equation to obtain the radius intersection, it becomes even more complex
 *
 *
 * */




/*
 * #include <stdio.h>

typedef double	t_vector __attribute__((vector_size(sizeof(double)*3)));

void			print(t_vector a)
{
	printf("{ %lf, %lf, %lf }\n", a[0], a[1], a[2]);
}

int				main(void)
{
	t_vector a;
	t_vector b;
	t_vector c;

	b = (t_vector){5.0, 6.0, 7.0};
	a = (t_vector){1.0, 2.0, 3.0};
	print(a);
	print(b);
	c = a + b;
	print(c);
	c = c * (t_vector){3.1, 3.1, 3.1};
	print(c);
	return (0);
}
 */