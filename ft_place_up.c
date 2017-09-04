/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 09:34:14 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/03 09:54:24 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_place_up_right(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	y = strat.highest.y - piece.size.y + 1;
	while (y <= strat.highest.y)
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
		y++;
	}
	return (0);
}

int		ft_place_up_left(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	y = strat.highest.y - piece.size.y + 1;
	while (y <= strat.highest.y)
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
		y++;
	}
	return (0);
}

int		ft_place_up(t_elem board, t_elem piece, t_strat strat)
{
	if (strat.highest.y == 0)
		return (0);
	if (strat.dir.x == 1)
	{
		if (ft_place_up_right(board, piece, strat))
			return (1);
	}
	else if (strat.dir.x == -1)
	{
		if (ft_place_up_left(board, piece, strat))
			return (1);
	}
	return (0);
}
