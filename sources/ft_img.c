/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:35:47 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/18 17:07:19 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_img.h"

void			ft_pixtoimg(t_img *i, t_point *p)
{
	i->str[((i->w * p->y) + p->x)] = p->colr.val;
}

static void		ft_writhelp(t_win *w)
{
	int start;
	int i;

	start = 1;
	i = 18;
	mlx_string_put(w->mlx, w->win, 5, start + (i * 0),
		0xF0F090, "\"+/-\" - scaling");
	mlx_string_put(w->mlx, w->win, 5, start + (i * 1),
		0xF0F090, "\"Up, Down, Left, Right\" - moving");
	mlx_string_put(w->mlx, w->win, 5, start + (i * 2),
		0xF0F090, "\"NUM[82]\" - precision");
	mlx_string_put(w->mlx, w->win, 5, start + (i * 3),
		0xF0F090, "\"NUM[46]\" - color shifting");
	mlx_string_put(w->mlx, w->win, 5, start + (i * 4),
		0xF0F090, "\"NUM*\" - on/off colors");
	mlx_string_put(w->mlx, w->win, 5, start + (i * 5),
		0xF0F090, "\"NUM_enter\" - on/off julia mouse move");
	mlx_string_put(w->mlx, w->win, 5, start + (i * 6),
		0xF0F090, "\"NUM0\" - set to default");
	mlx_string_put(w->mlx, w->win, 5, start + (i * 7),
		0xF0F090, "\"Esc\" - exit");
}

void			ft_drawimg(t_win *w)
{
	mlx_clear_window(w->mlx, w->win);
	mlx_put_image_to_window(w->mlx, w->win, w->img.ptr, 0, 0);
	//ft_writhelp(w);
}

unsigned int 	ft_colrlim(double c)
{
	unsigned int t;

	if (c < 0 || c == NAN)
		return (0);
	if (c == INFINITY)
		return (255);
	t = (unsigned int)c;
	return (t % 255);
}



