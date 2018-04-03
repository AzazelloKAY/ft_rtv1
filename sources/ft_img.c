/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:35:47 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/20 20:33:29 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_img.h"

void			ft_pixtoimg(t_img *i, t_point *p)
{
	i->str[((i->w * p->y) + p->x)] = p->colr.val;
}

void			ft_pixtoimg_shift(t_img *i, t_point *p)
{
	i->str[((i->w * (i->maxh - p->y)) + (p->x + i->maxw))] = p->colr.val;
}

//static void		ft_writhelp(t_win *w)
//{
//	int start;
//	int i;
//
//	start = 1;
//	i = 18;
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 0),
//		0xF0F090, "\"+/-\" - scaling");
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 1),
//		0xF0F090, "\"Up, Down, Left, Right\" - moving");
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 2),
//		0xF0F090, "\"NUM[82]\" - precision");
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 3),
//		0xF0F090, "\"NUM[46]\" - color shifting");
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 4),
//		0xF0F090, "\"NUM*\" - on/off colors");
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 5),
//		0xF0F090, "\"NUM_enter\" - on/off julia mouse move");
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 6),
//		0xF0F090, "\"NUM0\" - set to default");
//	mlx_string_put(w->mlx, w->win, 5, start + (i * 7),
//		0xF0F090, "\"Esc\" - exit");
//}

void			ft_drawimg(t_win *w)
{
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img.ptr, 0, 0);
	//ft_writhelp(w);
}

t_color 		ft_colr_add(t_color c1, t_color c2)
{
	unsigned int t;

	c1.chnl.a = ((t = c1.chnl.a + c2.chnl.a) <= 0xFF) ? t : 0xFF;
	c1.chnl.r = ((t = c1.chnl.r + c2.chnl.r) <= 0xFF) ? t : 0xFF;
	c1.chnl.g = ((t = c1.chnl.g + c2.chnl.g) <= 0xFF) ? t : 0xFF;
	c1.chnl.b = ((t = c1.chnl.b + c2.chnl.b) <= 0xFF) ? t : 0xFF;
	return (c1);
}

t_color			ft_colr_mul_scal(t_color c, double n)
{
	double t;

	if (n > 0xFF)
		c.val = 0xFFFFFF;
	c.chnl.a = ((t = c.chnl.a * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	c.chnl.r = ((t = c.chnl.r * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	c.chnl.g = ((t = c.chnl.g * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	c.chnl.b = ((t = c.chnl.b * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	return (c);

}
