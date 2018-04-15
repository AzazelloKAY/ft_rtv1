/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:55:41 by akokoshk          #+#    #+#             */
/*   Updated: 2018/04/15 17:58:13 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

//static void		ft_key1(int keycode, t_fract *f)
//{
//	if (keycode == 126)
//		f->mov_y -= (f->mov_y > -FT_MOVLIM) ? f->step : 0;
//	else if (keycode == 125)
//		f->mov_y += (f->mov_y < FT_MOVLIM) ? f->step : 0;
//	else if (keycode == 123)
//		f->mov_x -= (f->mov_x < FT_MOVLIM) ? f->step : 0;
//	else if (keycode == 124)
//		f->mov_x += (f->mov_x > -FT_MOVLIM) ? f->step : 0;
//	else if (keycode == 82)
//		f->fract_init(f);
//	else if (keycode == 91)
//		f->maxiter += (f->maxiter < 500) ? 1 : 0;
//	else if (keycode == 84)
//		f->maxiter -= (f->maxiter > 20) ? 1 : 0;
//	else if (keycode == 76)
//		f->live_mouse = (f->live_mouse == 0) ? 1 : 0;
//	else if (keycode == 67)
//		f->acid_color = (f->acid_color == 0) ? 1 : 0;
//	else if (keycode == 86)
//		f->colorshift -= (f->colorshift > 1) ? 1 : 0;
//	else if (keycode == 88)
//		f->colorshift += (f->colorshift < 30) ? 1 : 0;
//}
//
//static int		ft_mouse_mov(int x, int y, t_fract *f)
//{
//	if (f->live_mouse == 1 && f->live_mouse_move == 1)
//	{
//		f->mouse.im = y;
//		f->mouse.rl = x;
//		f->mmoved = 1;
//		f->fract_lonch(f);
//	}
//	return (0);
//}
//
//
//static int		ft_mouse_hook(int mkeycode, int x, int y, t_fract *f)
//{
//	((mkeycode == 5) ? ft_keycatch(69, f) : 0);
//	((mkeycode == 4) ? ft_keycatch(78, f) : 0);
//	if (mkeycode == 5 || mkeycode == 4 || mkeycode == 2)
//	{
//		f->mouse.im = y;
//		f->mouse.rl = x;
//		f->mmoved = 2;
//	}
//	f->fract_lonch(f);
//	return (0);
//}

static int		ft_keycatch(int keycode, t_scene *sc)
{

//	c->ang.x = 0; //++up; --down;
//	c->ang.y = -95; //++left; --right;
//	c->ang.z = 00; //++clockwise; --counterclockwise;

	if (keycode == e_key_esc)
		ft_exit_x(sc->w);
	else if (keycode == e_key_up)
		sc->cam->ang.x += (sc->cam->ang.x <= 85) ? 5 : 0;
	else if (keycode == e_key_down)
		sc->cam->ang.x -= (sc->cam->ang.x >= -85) ? 5 : 0;
	else if (keycode == e_key_left)
		sc->cam->ang.y += (sc->cam->ang.y <= 5000) ? 5 : 0;
	else if (keycode == e_key_right)
		sc->cam->ang.y -= (sc->cam->ang.y >= -5000) ? 5 : 0;

	if (keycode == e_key_up || keycode == e_key_down
		|| keycode == e_key_left || keycode == e_key_right)
		sc->cam->rad = calc_radians(sc->cam->ang);
//	else if (keycode == 24 || keycode == 69)
//	{
//		f->zoom *= (f->zoom < FT_ZOOMMAX) ? FT_ZOOMSTP : 1;
//		f->step /= (f->step > 0.0000001) ? FT_ZOOMSTP : 1;
//		f->maxiter *= (f->maxiter < 500) ? FT_ITERSTP : 1;
//	}
//	else if (keycode == 27 || keycode == 78)
//	{
//		f->zoom /= (f->zoom > 1) ? FT_ZOOMSTP : 1;
//		f->step *= (f->step < 0.1) ? FT_ZOOMSTP : 1;
//		f->maxiter /= (f->maxiter > 20) ? FT_ITERSTP : 1;
//	}
//	ft_key1(keycode, f);
//	f->fract_lonch(f);
	rt_redraw(sc);
	return (0);
}

void			ft_keyhookloop(t_scene *sc)
{
	mlx_hook(sc->w->win, 2, 0, ft_keycatch, sc);
//	mlx_hook(w->win, 4, 5, ft_mouse_hook, dat);
//	mlx_hook(w->win, 6, 1L << 6, ft_mouse_mov, dat);
	mlx_hook(sc->w->win, 17, 1L << 17, ft_exit_x, sc->w);
	mlx_loop(sc->w->mlx);
}


