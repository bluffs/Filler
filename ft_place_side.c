/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 09:40:20 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/16 15:37:35 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_place_left_up(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	x = strat.leftest.x - piece.size.x + 1;
	while (x <= strat.leftest.x)
	{
		y = -piece.size.y + 1;
		while (y < board.size.y)
		{
			if (ft_trypiece(board, piece, y, x))
			{
				ft_write_piece(y, x);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		ft_place_right_up(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	x = strat.rightest.x;
	while (x >= strat.rightest.x - piece.size.x)
	{
		y = -piece.size.y + 1;
		while (y < board.size.y)
		{
			if (ft_trypiece(board, piece, y, x))
			{
				ft_write_piece(y, x);
				return (1);
			}
			y++;
		}
		x--;
	}
	return (0);
}

int		ft_place_left(t_elem board, t_elem piece, t_strat strat)
{
	if (strat.leftest.x == 0)
		return (0);
	return (ft_place_left_up(board, piece, strat));
}

int		ft_place_right(t_elem board, t_elem piece, t_strat strat)
{
	if (strat.rightest.x == board.size.x - 1)
		return (0);
	return (ft_place_right_up(board, piece, strat));
}

int		ft_place_side(t_elem board, t_elem piece, t_strat strat)
{
	if (ft_place_right(board, piece, strat))
		return (1);
	if (ft_place_left(board, piece, strat))
		return (1);
	return (0);
}
