/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 11:12:40 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/31 09:26:30 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

void	ft_fill(t_all *all, int y, int x, int col)
{
	double		size_x;
	double		size_y;
	double		pos_x;
	double		pos_y;

	size_x = ((double)BOARD_SIZEX / (double)all->board->size.x);
	size_y = ((double)BOARD_SIZEY / (double)all->board->size.y);
	pos_y = ((double)y * size_y) + 1 - 1;
	while (++pos_y < (y + 1) * size_y - 2)
	{
		pos_x = ((double)x * size_x) + 1 - 1;
		while (++pos_x < (x + 1) * size_x - 2)
		{
			if (col == 1)
				all->img->array[(int)pos_y * all->img->sl +
					(int)pos_x * all->img->bpp / 8 + 0] = 255;
			if (col == 3 || col == 4)
				all->img->array[(int)pos_y * all->img->sl +
					(int)pos_x * all->img->bpp / 8 + 1] = 255;
			if (col == 2)
				all->img->array[(int)pos_y * all->img->sl +
					(int)pos_x * all->img->bpp / 8 + 2] = 255;
		}
	}
}

void	ft_fill_board(t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (y < all->board->size.y)
	{
		x = 0;
		while (x < all->board->size.x)
		{
			if (all->board->tab[y][x] == 'O')
				ft_fill(all, y, x, 1);
			else if (all->board->tab[y][x] == 'X')
				ft_fill(all, y, x, 2);
			else if (all->board->tab[y][x] == 'o')
				ft_fill(all, y, x, 3);
			else if (all->board->tab[y][x] == 'x')
				ft_fill(all, y, x, 4);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img->image, 0, 0);
}

int		ft_print_turns(t_all *all)
{
	int		color;
	char	*nb_turns;
	char	*sentence;

	nb_turns = ft_itoa(all->nb);
	color = 0x00FFFFFF;
	sentence = ft_strjoin("turns : ", nb_turns);
	if (mlx_string_put(all->mlx, all->win, BOARD_SIZEX + 100,
				PIECE_SIZEY + 100, color, sentence) == -1)
		return (-1);
	ft_strdel(&nb_turns);
	ft_strdel(&sentence);
	return (1);
}
