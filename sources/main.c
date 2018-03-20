/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:42:53 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/20 22:21:36 by akokoshk         ###   ########.fr       */
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

t_vec	canv_to_vp(t_vec point, t_img *i, t_cam *c)
{
	t_vec v;

	v.x = point.x * (c->vw / i->w);
	v.y = point.y * (c->vh / i->h);
	v.z = point.z;
	return (v);
}

t_color	rayTrace(t_ray *r, t_obj *o, int objNum)
{
	t_color	c;
	double	closest_t;
	double	cur_t;
	t_obj	*closest_o;

	c.val = 0;
	closest_t = INFINITY;
	closest_o = NULL;
	while (objNum--)										//ВАЖНО ПРАВИЛЬНО СОЗДАВАТЬ МАССИВ ОБЪЕКТОВ, ЛИБО ДОП ПЕРЕДАВАТЬ К_во
	{
		cur_t = o->intersect(r, o[objNum].obj);			//ТУТ ДОЛЖНО ВОЗВРАЩАТЬ ДВА ЗНАЧЕНИЯ
		if (cur_t > 0)
			printf("visable %10f\n", cur_t);


		if (cur_t >= 0 && cur_t < closest_t)
		{
			closest_t = cur_t;
			closest_o = &o[objNum];
		}
	}
	if (closest_o != NULL)
	{
		c = closest_o->colr;
		printf("r = %10f g = %10f b = %10f\n", c.chnl.r, c.chnl.g, c.chnl.b);
	}
	return (c);
}

void	ft_calc_scren(t_win	*w, t_obj *o, t_cam *c)
{
	t_point	p;
	t_ray	ray;

	ray.a = c->orig;
	p.y = w->img.maxh;
	while (p.y > w->img.minh)
	{
		p.x = w->img.minw;
		while (p.x < w->img.maxw)
		{
			//while (o != NULL) { o++; }

			ray.b.x = p.x;// - cam.x;
			ray.b.y = p.y;// - cam.y;
			ray.b.z = 1;// - cam.z;

			ray.b = canv_to_vp(ray.b, &w->img, c);

			ray.b = v_sub(ray.b, c->orig);	//?
			ray.b = v_normalise(ray.b);		//?

			p.colr = rayTrace(&ray, o, 1);

			ft_pixtoimg_shift(&w->img, &p);


			p.x++;
		}
		p.y--;
	}
}


int main()
{
	//test_rtv1(&o);



	t_obj		*o;
	t_win		*w;
	t_cam		*c;

	w = ft_init_mlx("test rtv");
	ft_init_img(w);
	c = cam_new(0, 0, -1);
	o = rt_obj_new(2);
	o[0].colr.val = 0xFF00;
	o[0].intersect = rt_sphere_intersect;
	o[0].obj = (void*)rt_new_sphere(0, 0, 1000, 20);

	ft_calc_scren(w, o, c);

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