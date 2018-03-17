/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init_destr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:00:34 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/17 22:04:16 by akokoshk         ###   ########.fr       */
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

int				ft_init_img(t_win *w)
{
	if (w->img.ptr)
		mlx_destroy_image(w->mlx, w->img.ptr);
	w->img.h = w->h;
	w->img.w = w->w;
	if (!(w->img.ptr = mlx_new_image(w->mlx, w->img.w, w->img.h)))
		return (1);
	w->img.bitperpix = sizeof(int) * 8;
	w->img.size_line = sizeof(int) * w->img.w;
	w->img.endian = 0;
	if (!(w->img.str = (uint32_t*)mlx_get_data_addr(w->img.ptr,
													&(w->img.bitperpix), &(w->img.size_line), &(w->img.endian))))
		return (1);
	return (0);
}

void			ft_destroy_all(void *dat)
{

}

