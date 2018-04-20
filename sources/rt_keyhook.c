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

static void		ft_key1(int keycode, t_scene *sc)
{
	if (keycode == e_key_esc)
		ft_exit_x(sc->w);
	else if (keycode == e_key_up)
		sc->cam->ang.x += (sc->cam->ang.x <= 85) ? 15 : 0;
	else if (keycode == e_key_down)
		sc->cam->ang.x -= (sc->cam->ang.x >= -85) ? 15 : 0;
	else if (keycode == e_key_left)
		sc->cam->ang.y += (sc->cam->ang.y <= 5000) ? 15 : 0;
	else if (keycode == e_key_right)
		sc->cam->ang.y -= (sc->cam->ang.y >= -5000) ? 15 : 0;
	else if (keycode == e_key_w)
		sc->cam->orig.z += (sc->cam->orig.z <= 200) ? 15 : 0;
	else if (keycode == e_key_s)
		sc->cam->orig.z -= (sc->cam->orig.z >= -200) ? 15 : 0;
	else if (keycode == e_key_d)
		sc->cam->orig.x += (sc->cam->orig.x <= 200) ? 15 : 0;
	else if (keycode == e_key_a)
		sc->cam->orig.x -= (sc->cam->orig.x >= -200) ? 15 : 0;
	else if (keycode == e_key_space)
		sc->cam->orig.y += (sc->cam->orig.y <= 200) ? 15 : 0;
	else if (keycode == e_key_lctrl)
		sc->cam->orig.y -= (sc->cam->orig.y >= -200) ? 15 : 0;
}

static int		ft_keycatch(int keycode, t_scene *sc)
{
	ft_key1(keycode, sc);

	if (keycode == e_key_up || keycode == e_key_down
		|| keycode == e_key_left || keycode == e_key_right)
		sc->cam->rad = calc_radians(sc->cam->ang);
	rt_redraw(sc);

	return (0);
}

void			ft_keyhookloop(t_scene *sc)
{
	mlx_hook(sc->w->win, 2, 0, ft_keycatch, sc);
	mlx_hook(sc->w->win, 17, 1L << 17, ft_exit_x, sc->w);
	mlx_loop(sc->w->mlx);
}


