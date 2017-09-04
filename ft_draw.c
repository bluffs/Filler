/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:46:57 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/22 11:16:27 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

void	ft_open_image(t_all *all)
{
	all->img->image = mlx_new_image(all->mlx, BOARD_SIZEX, BOARD_SIZEY);
	all->img->array = (unsigned char *)mlx_get_data_addr(all->img->image,
			&(all->img->bpp), &(all->img->sl), &(all->img->endian));
}

void	ft_draw_hor(t_image *img, int y, int size_x, int size_y)
{
	int		x;

	x = 0;
	if (y < size_y)
	{
		while (x < size_x)
		{
			img->array[y * img->sl + x * img->bpp / 8 + 0] = 255;
			img->array[y * img->sl + x * img->bpp / 8 + 1] = 255;
			img->array[y * img->sl + x * img->bpp / 8 + 2] = 255;
			++x;
		}
	}
}

void	ft_draw_ver(t_image *img, int x, int size_x, int size_y)
{
	int		y;

	y = 0;
	if (x < size_x)
	{
		while (y < size_y)
		{
			img->array[y * img->sl + x * img->bpp / 8 + 0] = 255;
			img->array[y * img->sl + x * img->bpp / 8 + 1] = 255;
			img->array[y * img->sl + x * img->bpp / 8 + 2] = 255;
			++y;
		}
	}
}

void	ft_draw_border(t_image *img, int size_x, int size_y)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++x < size_x)
	{
		img->array[0 * img->sl + x * img->bpp / 8 + 0] = 255;
		img->array[0 * img->sl + x * img->bpp / 8 + 1] = 255;
		img->array[0 * img->sl + x * img->bpp / 8 + 2] = 255;
		img->array[(size_y - 1) * img->sl + x * img->bpp / 8 + 0] = 255;
		img->array[(size_y - 1) * img->sl + x * img->bpp / 8 + 1] = 255;
		img->array[(size_y - 1) * img->sl + x * img->bpp / 8 + 2] = 255;
	}
	while (++y < size_y)
	{
		img->array[y * img->sl + 0 * img->bpp / 8 + 0] = 255;
		img->array[y * img->sl + 0 * img->bpp / 8 + 1] = 255;
		img->array[y * img->sl + 0 * img->bpp / 8 + 2] = 255;
		img->array[y * img->sl + (size_x - 1) * img->bpp / 8 + 0] = 255;
		img->array[y * img->sl + (size_x - 1) * img->bpp / 8 + 1] = 255;
		img->array[y * img->sl + (size_x - 1) * img->bpp / 8 + 2] = 255;
	}
}

void	ft_draw_board(t_all *all)
{
	int		nb;
	int		nb_line;
	double	spacing;

	ft_draw_border(all->img, BOARD_SIZEX, BOARD_SIZEY);
	nb = 1;
	nb_line = all->board->size.x + 1;
	spacing = (double)BOARD_SIZEX / (double)all->board->size.x;
	while (nb < nb_line)
	{
		ft_draw_ver(all->img, nb * spacing, BOARD_SIZEX, BOARD_SIZEY);
		nb++;
	}
	nb = 1;
	nb_line = all->board->size.y + 1;
	spacing = (double)BOARD_SIZEY / (double)all->board->size.y;
	while (nb < nb_line)
	{
		ft_draw_hor(all->img, nb * spacing, BOARD_SIZEX, BOARD_SIZEY);
		++nb;
	}
	sleep(2);
}
