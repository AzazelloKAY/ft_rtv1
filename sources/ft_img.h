/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:19:45 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/18 16:50:39 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

# include <math.h>
# include "../libft/libft.h"
//# include <mlx.h>
# include </usr/local/include/mlx.h>
# define WINHEIGHT 600
# define WINWIDTH 900


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

typedef struct		s_point
{
	int			y;
	int			x;
	t_color		colr;
}					t_point;

typedef struct		s_img
{
	void		*ptr;
	uint32_t	*str;
	int			bitperpix;
	int			size_line;
	int			endian;
	int			h;
	int			w;
}					t_img;

typedef struct		s_win
{
	void		*mlx;
	void		*win;
	int			h;
	int			w;
	t_img		img;
}					t_win;

/*
*** ft_img.c
*/

void			ft_pixtoimg(t_img *i, t_point *p);
void			ft_drawimg(t_win *w);
unsigned int 	ft_colrlim(double c);

/*
*** ft_img_init_destr.c
*/

t_win			*ft_init_mlx(char *name);
int				ft_init_img(t_win *w);
void			ft_destroy_all(t_win *w);
int				ft_exit_x(t_win *w);

/*
*** ft_img_keyhook.c
*/

void			ft_keyhookloop(t_win *w, void *dat);

#endif
