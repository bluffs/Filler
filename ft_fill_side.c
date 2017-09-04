/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_side.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:37:42 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/19 11:39:36 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_fill_left(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	if (strat.op_rightest.x < board.size.x / 2)
		x = board.size.x / 2;
	else
		x = strat.op_rightest.x;
	while (x - piece.size.x + 1 >= 0)
	{
		y = -piece.size.y + 1;
		while (y < board.size.y - 1)
		{
			if (ft_trypiece(board, piece, y, x))
			{
				ft_write_piece(y, x);
				return (1);
			}
			++y;
		}
		--x;
	}
	return (0);
}

int		ft_fill_right(t_elem board, t_elem piece, t_strat strat)
{
	int		y;
	int		x;

	if (strat.op_leftest.x > board.size.x / 2 - 1)
		x = board.size.x / 2 - 1;
	else
		x = strat.op_leftest.x - piece.size.x + 1;
	while (x < board.size.x - 1)
	{
		y = -piece.size.y + 1;
		while (y < board.size.y - 1)
		{
			if (ft_trypiece(board, piece, y, x))
			{
				ft_write_piece(y, x);
				return (1);
			}
			++y;
		}
		++x;
	}
	return (0);
}

int		ft_fill_side(t_elem board, t_elem piece, t_strat strat)
{
	if (strat.highest.y == 0 && strat.lowest.y == board.size.y - 1)
	{
		if (strat.dir.x >= 0)
			return (ft_fill_right(board, piece, strat));
		else
			return (ft_fill_left(board, piece, strat));
	}
	return (0);
}
