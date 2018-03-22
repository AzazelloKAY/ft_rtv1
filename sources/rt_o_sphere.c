/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_o_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:19:30 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/22 21:35:55 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"


int		rt_sphere_intersect(t_ray *r, void *obj, void *res)
{
	t_sphere	*s;
	t_vec		qabc;
	t_vec		len;
	t_vec2		qres;

	s = (t_sphere*)obj;
	qabc.x = v_mul_s(r->b, r->b);
	len = v_sub(r->a, s->centr);
	qabc.y = 2.0 * v_mul_s(r->b, len);
	qabc.z = v_mul_s(len, len) - (s->radius * s->radius);
	if (v_quad_equ(qabc.x, qabc.y, qabc.z, &qres))
	{
		*(t_vec2*)res = qres;
		return (1);
	}
	else
		return (0);
}

t_sphere	*rt_new_sphr(double x, double y, double z, double r)
{
	t_sphere *s;

	if (!(s = ft_memalloc(sizeof(t_sphere))))
		return (NULL);
	s->radius = r;
	s->centr.x = x;
	s->centr.y = y;
	s->centr.z = z;
	return (s);
}

void 		rt_sphr_obj(t_obj *o, t_vec cntr, double r, uint32_t colr)
{
	o->colr.val = colr;
	o->intersect = rt_sphere_intersect;
	o->objp = rt_new_sphr(cntr.x, cntr.y, cntr.z, r);
}

/*
 * точка пересечеия(удара луча O+tD) - центр сферы
 * обязательно нормализуем
 */




//TEST SHITTT
//
//void 	test_rtv1(t_obj *o)
//{
//	t_win	*w;
//	t_point p;
//	t_vec	cam;
//	t_ray	r;
//
//	w = ft_init_mlx("test rtv");
//	ft_init_img(w);
//
//
//	cam.x = 450;
//	cam.y = 300;
//	cam.z = -100;
//
//	r.a = cam;
//	r.b.z = 1;
//
//	p.colr.val = 0;
//	p.y = 0;
//	while (p.y < w->img.h)
//	{
//		p.x = 0;
//		while (p.x < w->img.w)
//		{
//
//			r.b.x = p.x;// - cam.x;
//			r.b.y = p.y;// - cam.y;
//			r.b.z = 50;// - cam.z;
//			r.b = v_sub(r.b, cam);
//			r.b = v_normalise(r.b);
//
//			if(p.x == 450 && p.y == 300)
//				printf("test");
//			p.colr.chnl.g = ft_colrlim(o->intersect(&r, o->obj));
////			if (rt_sphere_intersect( &r, (void*)&s) > 0)
////				p.colr.chnl.g = 250;
//			ft_pixtoimg(&w->img, &p);
//			p.x++;
//		}
//		p.y++;
//	}
//
//	ft_drawimg(w);
//
//	ft_keyhookloop(w, 0);
//}
//
//void 	test_rtv2(t_obj *o)
//{
//	t_win	*w;
//	t_point p;
//	t_vec	cam;
//	t_ray	r;
//
//	w = ft_init_mlx("test rtv");
//	ft_init_img(w);
//
//
//	cam.x = 450;
//	cam.y = 300;
//	cam.z = -100;
//
//	r.a = cam;
//	r.b.z = 1;
//
//	p.colr.val = 0;
//	p.y = 0;
//	while (p.y < w->img.h)
//	{
//		p.x = 0;
//		while (p.x < w->img.w)
//		{
//
//			r.b.x = p.x;// - cam.x;
//			r.b.y = p.y;// - cam.y;
//			r.b.z = 50;// - cam.z;
//			r.b = v_sub(r.b, cam);
//			r.b = v_normalise(r.b);
//
//			if(p.x == 450 && p.y == 300)
//				printf("test");
//			p.colr.chnl.g = ft_colrlim(o->intersect(&r, o->obj));
//
//			ft_pixtoimg(&w->img, &p);
//			p.x++;
//		}
//		p.y++;
//	}
//
//	ft_drawimg(w);
//
//	ft_keyhookloop(w, 0);
//}



// осознать переписать!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//typedef
//struct {
//	// указатель на область данных, содержащую параметры конкретного примитива
//	// в случае полигона: координаты вершин, цвет (или битмапка с текстурой), свойства материала
//	// в случае сферы: координаты центра, радиус, и т.п.
//	void * data;
//
//	// указатель на функцию, которая умеет обрабатывать примитив,
//	// на который ссылается указатель data
//	Boolean (*intersect)(const void * data,
//						 const Point3d ray_start_point,
//						 const Vector3d ray,
//			// сюда будет сохранятся точка пересечения луча и примитива
//						 Point3d * const intersection_point);
//
//	// получение цвета в точке пересечения
//	// здесь можно возвращать просто цвет объекта
//	// или обеспечить процедурную генерацию текстуры
//	// или использовать загруженную из файла текстуру :)
//	Color (*get_color)(const void * data,
//					   const Point3d intersection_point);
//
//	// получение вектора нормали в точке пересечения (используется для рассчёта освещённости)
//	// в случае сферы и полигона - вектор нормали можно рассчитать аналитически
//	// как вариант, вместо аналитечских рассчётов - объект может содержать карту нормалей
//	Vector3d (*get_normal_vector)(const void * data,
//								  const Point3d intersection_point);
//
//	// вызывается рендером перед удалением Object3d
//	// тут можно освобождать ресурсы, связанные с объектом
//	// например, удалять текстуры
//	void (*release_data)(void * data);
//}
//		Object3d;




// ... инклуды
//
//typedef
//struct {
//	Point3d center;
//	Float radius;
//	Color color;
//}
//		Sphere;
//
//// ... декларации функций
//
//// "конструктор" сферы
//Object3d *
//new_sphere(const Point3d center,
//		   const Float radius,
//		   const Color color) {
//
//	Sphere * sphere = malloc(sizeof(Sphere));
//	sphere->center = center;
//	sphere->radius = radius;
//	sphere->color = color;
//
//	// упаковываем сферу в обобщённую структуру 3D объекта
//	Object3d * obj = malloc(sizeof(Object3d));
//	obj->data = sphere;
//
//	// добавляем функции, которые умеют работать со структурой Sphere
//	obj->get_color = get_sphere_color;
//	obj->get_normal_vector = get_sphere_normal_vector;
//	obj->intersect = intersect_sphere;
//	obj->release_data = release_sphere_data;
//
//	return obj;
//}
//
//// цвет сферы всюду одинаковый
//// но здесь можно реализовать процедурную генерацию текстуры
//static Color
//get_sphere_color(const void * data,
//				 const Point3d intersection_point) {
//	const Sphere * sphere = data;
//	return sphere->color;
//}
//
//// вычисляем аналитически вектор нормали в точке на поверхности сферы
//// сюда можно впилить Bump Mapping
//static Vector3d
//get_sphere_normal_vector(const void * data,
//						 const Point3d intersection_point) {
//	const Sphere * sphere = data;
//	// vector3dp - служебная функция, которая создаёт вектор по двум точкам
//	Vector3d n = vector3dp(sphere->center, intersection_point);
//	normalize_vector(&n);
//	return n;
//}
//
//// пересечение луча и сферы
//static Boolean
//intersect_sphere(const void * data,
//				 const Point3d ray_start_point,
//				 const Vector3d ray,
//				 Point3d * const intersection_point) {
//	const Sphere * sphere = data;
//	// чтобы найти точку пересечения луча и сферы - нужно решить квадратное уравнение
//	// полную реализацию метода можно найти в исходниках на GitHub
//}
//
//// "деструктор" сферы
//void
//release_sphere_data(void * data) {
//	Sphere * sphere = data;
//	// если бы сфера содержала текстуры - их нужно было бы здесь освободить
//	free(sphere);
//}


