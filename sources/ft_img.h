/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:19:45 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 17:41:25 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

# include <math.h>
# include "../libft/libft.h"
//# include <mlx.h>
//# include </usr/local/include/mlx.h>
# include </usr/local/include/mlx.h>
# define WINHEIGHT 600
# define WINWIDTH 900

typedef enum		e_keycode
{
	e_key_esc = 53,
	e_key_space = 49,
	e_key_entr = 36,
	e_key_up = 126,
	e_key_left = 123,
	e_key_down = 125,
	e_key_right = 124,
	e_key_lsift = 257,
	e_key_lctrl = 256,
	e_key_tab = 48,
	e_key_lalt = 261,
	e_key_lcmd = 259,
	e_key_w = 13,
	e_key_a = 0,
	e_key_s = 1,
	e_key_d = 2,
	e_keynum_up = 91,
	e_keynum_down = 84,
	e_keynum_right = 88,
	e_keynum_left = 86,
	e_keynum_centre = 87,
	e_keynum_upleft = 89,
	e_keynum_upright = 92,
	e_keynum_dwnleft = 83,
	e_keynum_dwnright = 85,
	e_keynum_zero = 82,
	e_keynum_entr = 76,
	e_keynum_plus = 69,
	e_keynum_minus = 78,
	e_keynum_mult = 67,
	e_keynum_div = 75,
	e_keynum_equal = 81,
}					t_keycode;

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
	int			minh;
	int			maxh;
	int			minw;
	int			maxw;
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
void			ft_pixtoimg_shift(t_img *i, t_point *p);
void			ft_drawimg(t_win *w);
uint32_t		colr_scal(uint32_t colr, double n);
uint32_t 		colr_add(uint32_t colr1, uint32_t colr2);

/*
*** ft_img_init_destr.c
*/

t_win			*ft_init_mlx(char *name);
int				fr_remake_img(t_win *w);
int				ft_init_img(t_win *w);
void			ft_destroy_all(t_win *w);
int				ft_exit_x(t_win *w);

#endif
