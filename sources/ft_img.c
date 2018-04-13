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

#include "ft_img.h"

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

uint32_t 		colr_add(uint32_t colr1, uint32_t colr2)
{
	unsigned int t;
	t_color	c1;
	t_color	c2;

	c1.val = colr1;
	c2.val = colr2;

	t = c1.chnl.a + c2.chnl.a;
	c1.chnl.a = (t <= 0xFF) ? t : 0xFF;
	t = c1.chnl.r + c2.chnl.r;
	c1.chnl.r = (t <= 0xFF) ? t : 0xFF;
	t = c1.chnl.g + c2.chnl.g;
	c1.chnl.g = (t <= 0xFF) ? t : 0xFF;
	t = c1.chnl.b + c2.chnl.b;
	c1.chnl.b = (t <= 0xFF) ? t : 0xFF;
	return (c1.val);
}

uint32_t		colr_scal(uint32_t colr, double n)
{
	double t;
	t_color	c;

	c.val = colr;

	if (n > 0xFF)
		n = 0xFF;
	c.chnl.a = ((t = c.chnl.a * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	c.chnl.r = ((t = c.chnl.r * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	c.chnl.g = ((t = c.chnl.g * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	c.chnl.b = ((t = c.chnl.b * n) <= 0xFF) ? (unsigned int)t : 0xFF;
	return (c.val);

}
