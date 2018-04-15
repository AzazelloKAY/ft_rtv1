/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:42:53 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 18:15:25 by akokoshk         ###   ########.fr       */
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


void	rt_redraw(t_scene *sc)
{
	rt_calc_scren(sc->w, sc->cam, sc);
	ft_drawimg(sc->w);
}

int 	main()
{
	t_scene		*sc;

	sc = rt_new_scene(6, 3); //onj num //light num

	sc->w = ft_init_mlx("akokoshko`s rtv1");
	ft_init_img(sc->w);
	sc->cam = cam_new(0, 0, -0.5, 95);


	//AMBI LIGHT
	rt_set_ambi_light(&sc->light[0], 0.18);
	//POINT LIGHT
	double		lxyz[3] = {0, 200, 600};//{-150.0, 150, 150};
	rt_set_point_light(&sc->light[1], lxyz, 0.45, 0);
	sc->light[1].colr.val = 0x0000ff;

	double		l2xyz[3] = {0, 200, 150};//{-150.0, 150, 150};
	rt_set_point_light(&sc->light[2], l2xyz, 0.43, 0);
	sc->light[2].colr.val = 0xFFFFff;


	//1
	double s1xyz[3] = {60, 0, 490};
	rt_sphr_obj(&sc->obj[0], rt_new_sphr(s1xyz, 60), 0x00FF00);
	//2
	double s2xyz[3] = {-20, 0, 500};
	rt_sphr_obj(&sc->obj[1], rt_new_sphr(s2xyz, 50), 0xFF0000);

	//3
	t_vec v;
	v.x = -100;
	v.y = 100;
	v.z = 0;
	double coxyz[3] = {20.0, -100.0, 540.0};
	double k_minm_maxm[3] = {10, 4.0, 200.0};
	rt_cone_obj(&sc->obj[2], rt_new_cone(coxyz, v, k_minm_maxm), 0x254F21);


	//4
	t_vec n;
	n.x = 200;
	n.y = 100;
	n.z = 500;
	double cyxyz[3] = {-150.0, -100.0, 100.0};
	rt_cylindr_obj(&sc->obj[3], rt_new_cylindr(cyxyz, 9.2, n, 1), 0x1234C6);

	//5
	n.x = 0;
	n.y = 1;
	n.z = 0;
	double pxyz[3] = {0.0, 250.0, 0.0};
	rt_plane_obj(&sc->obj[4], rt_new_plane(pxyz, n), 0x00F0F0);

	//6
	n.x = 0;
	n.y = -1;
	n.z = 0;
	double p2xyz[3] = {0.0, -250.0, 0.0};
	rt_plane_obj(&sc->obj[5], rt_new_plane(p2xyz, n), 0xF0C173);





	rt_redraw(sc);



	ft_keyhookloop(sc);

    return 0;
}

