/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:19:30 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/18 18:09:41 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"


double		rt_sphere_intersect(t_ray *r, void *obj)
{
	double		a;
	double		b;
	double		c;
	t_sphere	*s;
	t_vec		len;

	s = (t_sphere*)obj;
	a = v_mul_s(r->b, r->b);
	len = v_sub(r->a, s->centr);
	b = 2.0 * v_mul_s(r->b, len);
	c = v_mul_s(len, len) - (s->radius * s->radius);
//	if (quad_equ(a, b, c) == NAN)
//		return (0);
//	else
//		return (1);
	return (v_quad_equ(a, b, c));
}




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


