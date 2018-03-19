/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init_destr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:00:34 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/19 22:14:58 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_img.h"

t_win			*ft_init_mlx(char *name)
{
	t_win	*w;

	if (!(w = ft_memalloc(sizeof(t_win))))
		return (NULL);
	w->h = WINHEIGHT;
	w->w = WINWIDTH;
	if (!(w->mlx = mlx_init()))
		return (NULL);
	if (!(w->win = mlx_new_window
			(w->mlx, w->w, w->h, (name != NULL) ? name : "akokoshk")))
		return (NULL);
	return (w);
}

int				fr_remake_img(t_win *w)
{
	if (!(w->img.ptr = mlx_new_image(w->mlx, w->img.w, w->img.h)))
		return (1);
	if (!(w->img.str = (uint32_t*)mlx_get_data_addr(w->img.ptr,
		&(w->img.bitperpix), &(w->img.size_line), &(w->img.endian))))
		return (1);
	return (0);
}

int				ft_init_img(t_win *w)
{
	if (w->img.ptr)
		mlx_destroy_image(w->mlx, w->img.ptr);
	w->img.h = w->h;
	w->img.w = w->w;
	w->img.bitperpix = sizeof(int) * 8;
	w->img.size_line = sizeof(int) * w->img.w;
	w->img.endian = 0;

	w->img.maxh = (w->h / 2);
	w->img.minh = -(w->h / 2);
	w->img.maxw = (w->w / 2);
	w->img.minw = - (w->w / 2);

	return (fr_remake_img(w));
}

void			ft_destroy_all(t_win *w)
{
	if (w->img.ptr)
		mlx_destroy_image(w->mlx, w->img.ptr);
	mlx_destroy_window(w->mlx, w->win);
}

int				ft_exit_x(t_win *w)
{
	ft_destroy_all(w);
	exit(0);
}


