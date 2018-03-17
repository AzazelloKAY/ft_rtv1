/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:42:53 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/17 21:13:44 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_rtv1.h"

void	print_v(t_vec *a)
{
	printf(">x=%10f y=%10f z=%10f\n", a->x, a->y, a->z);
}
int main()
{
	t_vec a;
	t_vec b;

	a.x = 1;
	a.y = 23.124;
	a.z = 5.55;

	b.x = 2;
	b.y = 30.124;
	b.z = 6.55;

	t_vec *z = ft_memalloc(sizeof(t_vec));
	*z = v_add(a, b);


	print_v(&a);
	print_v(&b);

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