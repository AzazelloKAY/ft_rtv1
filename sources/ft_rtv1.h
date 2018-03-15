/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:46:57 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/15 21:31:14 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H

# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
//# include <mlx.h>
# include </usr/local/include/mlx.h>

//typedef double	t_vector __attribute__((vector_size(sizeof(double)*3)));


/*
** move to extrnal lib
*/

typedef	struct		s_point2
{
	double x;
	double y;
}					t_point2;

typedef	struct		s_point
{
	double x;
	double y;
	double z;
}					t_point;

typedef struct		s_colorchannels
{
	unsigned int	b : 8;
	unsigned int	g : 8;
	unsigned int	r : 8;
	unsigned int	a : 8;
}					t_colorchannels;

typedef union		u_color
{
	unsigned int		val;
	t_colorchannels		chnl;
}					t_color;


/*
** FT_RTv1 sources
*/

typedef struct		s_vec
{
	t_point a;
	t_point b;
}					t_vec;

typedef struct		s_obj
{
	void	*obj;
	int (*intersect)(void *obj, t_point r_start, t_vec ray, t_point *cross_p);

}					t_obj;

#endif
