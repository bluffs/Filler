/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 09:30:15 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/22 08:54:11 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_place_down_right(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	y = strat.lowest.y;
	while (y >= strat.lowest.y - piece.size.y + 1)
	{
		x = board.size.x;
		while (x + piece.size.x >= 1)
		{
			if (ft_trypiece(board, piece, y, x))
			{
				ft_write_piece(y, x);
				return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

int		ft_place_down_left(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	y = strat.lowest.y;
	while (y >= strat.lowest.y - piece.size.y + 1)
	{
		x = -piece.size.x + 1;
		while (x <= board.size.x)
		{
			if (ft_trypiece(board, piece, y, x))
			{
				ft_write_piece(y, x);
				return (1);
			}
			x++;
		}
		y--;
	}
	return (0);
}

int		ft_place_down(t_elem board, t_elem piece, t_strat strat)
{
	if (strat.lowest.y == board.size.y - 1)
		return (0);
	if (strat.dir.x == 1)
	{
		if (ft_place_down_right(board, piece, strat))
			return (1);
	}
	else if (strat.dir.x == -1)
	{
		if (ft_place_down_left(board, piece, strat))
			return (1);
	}
	return (0);
}
