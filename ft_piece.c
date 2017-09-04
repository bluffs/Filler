/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:58:57 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/31 09:13:34 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

void	ft_open_piece(t_all *all)
{
	all->img_piece->image = mlx_new_image(all->mlx, PIECE_SIZEX,
			PIECE_SIZEY + TURN_SIZEY);
	all->img_piece->array = (unsigned char *)mlx_get_data_addr(
		all->img_piece->image, &(all->img_piece->bpp), &(all->img_piece->sl),
		&(all->img_piece->endian));
}

void	ft_draw_piece(t_all *all)
{
	int		nb;
	int		nb_line;
	double	spacing;

	ft_open_piece(all);
	ft_draw_border(all->img_piece, PIECE_SIZEX, PIECE_SIZEY);
	nb = 0;
	nb_line = all->piece->size.x + 1;
	spacing = (double)PIECE_SIZEX / (double)all->piece->size.x;
	while (++nb < nb_line)
		ft_draw_ver(all->img_piece, nb * spacing, PIECE_SIZEX, PIECE_SIZEY);
	nb = 1;
	nb_line = all->piece->size.y + 1;
	spacing = (double)PIECE_SIZEY / (double)all->piece->size.y;
	while (nb < nb_line)
	{
		ft_draw_hor(all->img_piece, nb * spacing, PIECE_SIZEX, PIECE_SIZEY);
		++nb;
	}
	ft_fill_piece(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img_piece->image,
			SIZEX - PIECE_SIZEX, 0);
	ft_print_turns(all);
	sleep(all->wait);
}

void	ft_fill_p(t_all *all, int y, int x)
{
	double		size_x;
	double		size_y;
	double		pos_x;
	double		pos_y;

	size_x = ((double)PIECE_SIZEX / (double)all->piece->size.x);
	size_y = ((double)PIECE_SIZEY / (double)all->piece->size.y);
	pos_x = ((double)x * size_x) + 1;
	pos_y = ((double)y * size_y) + 1;
	while (pos_y < (y + 1) * size_y - 2)
	{
		pos_x = ((double)x * size_x) + 1;
		while (pos_x < (x + 1) * size_x - 2)
		{
			all->img_piece->array[(int)pos_y * all->img_piece->sl +
				(int)pos_x * all->img_piece->bpp / 8 + 1] = 255;
			++pos_x;
		}
		++pos_y;
	}
}

void	ft_fill_piece(t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (y < all->piece->size.y)
	{
		x = 0;
		while (x < all->piece->size.x)
		{
			if (all->piece->tab[y][x] == '*')
				ft_fill_p(all, y, x);
			++x;
		}
		++y;
	}
}

void	ft_draw_piece_border(t_image *img)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++x < PIECE_SIZEX)
	{
		img->array[0 * img->sl + x * img->bpp / 8 + 0] = 255;
		img->array[0 * img->sl + x * img->bpp / 8 + 1] = 255;
		img->array[0 * img->sl + x * img->bpp / 8 + 2] = 255;
		img->array[(PIECE_SIZEY - 1) * img->sl + x * img->bpp / 8 + 0] = 255;
		img->array[(PIECE_SIZEY - 1) * img->sl + x * img->bpp / 8 + 1] = 255;
		img->array[(PIECE_SIZEY - 1) * img->sl + x * img->bpp / 8 + 2] = 255;
	}
	while (++y < PIECE_SIZEY)
	{
		img->array[y * img->sl + 0 * img->bpp / 8 + 0] = 255;
		img->array[y * img->sl + 0 * img->bpp / 8 + 1] = 255;
		img->array[y * img->sl + 0 * img->bpp / 8 + 2] = 255;
		img->array[y * img->sl + (PIECE_SIZEX - 1) * img->bpp / 8 + 0] = 255;
		img->array[y * img->sl + (PIECE_SIZEX - 1) * img->bpp / 8 + 1] = 255;
		img->array[y * img->sl + (PIECE_SIZEX - 1) * img->bpp / 8 + 2] = 255;
	}
}
