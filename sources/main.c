/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:42:53 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/19 19:40:41 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_rtv1.h"

void	print_v(t_vec *a)
{
	printf(">x=%10f y=%10f z=%10f\n", a->x, a->y, a->z);
}


void 	test_rtv1(t_obj *o)
{
	t_win	*w;
	t_point p;
	t_vec	cam;
	t_ray	r;

	w = ft_init_mlx("test rtv");
	ft_init_img(w);


	cam.x = 450;
	cam.y = 300;
	cam.z = -100;

	r.a = cam;
	r.b.z = 1;

	p.colr.val = 0;
	p.y = 0;
	while (p.y < w->img.h)
	{
		p.x = 0;
		while (p.x < w->img.w)
		{

			r.b.x = p.x;// - cam.x;
			r.b.y = p.y;// - cam.y;
			r.b.z = 50;// - cam.z;
			r.b = v_sub(r.b, cam);
			r.b = v_normalise(r.b);

			if(p.x == 450 && p.y == 300)
				printf("test");
			p.colr.chnl.g = ft_colrlim(o->intersect(&r, o->obj));
//			if (rt_sphere_intersect( &r, (void*)&s) > 0)
//				p.colr.chnl.g = 250;
			ft_pixtoimg(&w->img, &p);
			p.x++;
		}
		p.y++;
	}

	ft_drawimg(w);

	ft_keyhookloop(w, 0);
}

int main()
{
	t_obj		o;
	t_sphere	*s;

	s = rt_new_sphere(100, 450, 300, 50);

	o.colr.val = 0xFF00;
	o.intersect = rt_sphere_intersect;
	o.obj = (void*)s;


	test_rtv1(&o);
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