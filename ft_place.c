/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:32:33 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/22 09:01:19 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_invalidate(int ver, int hor, t_elem board, char c)
{
	if ((ver < 0 || hor < 0 || ver >= board.size.y ||
				hor >= board.size.x) && c == '*')
		return (1);
	else if (c == '*' && (board.tab[ver][hor] == board.opponent ||
				board.tab[ver][hor] == ft_tolower(board.opponent)))
		return (1);
	return (0);
}

int		ft_trypiece(t_elem board, t_elem piece, int y, int x)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (j < piece.size.y)
	{
		i = 0;
		while (i < piece.size.x)
		{
			if (ft_invalidate(y + j, x + i, board, piece.tab[j][i]))
				return (0);
			else if (y + j >= 0 && y + j < board.size.y && x + i >= 0 && x + i
					< board.size.x && piece.tab[j][i] == '*' &&
					(board.tab[y + j][x + i] == board.player ||
					board.tab[y + j][x + i] == ft_tolower(board.player)))
				count++;
			i++;
		}
		j++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		ft_place_force(t_elem board, t_elem piece)
{
	int		y;
	int		x;

	y = -piece.size.y + 1;
	while (y < board.size.y)
	{
		x = -piece.size.x + 1;
		while (x < board.size.x)
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

void	ft_write_piece(int y, int x)
{
	ft_putnbr(y);
	write(1, " ", 1);
	ft_putnbr(x);
	write(1, "\n", 1);
}

int		ft_place(t_elem board, t_elem piece, t_strat *strat)
{
	ft_analyse_board(board, strat);
	if (ft_place_up(board, piece, *strat))
		return (1);
	else if (ft_place_down(board, piece, *strat))
		return (1);
	else if (ft_place_side(board, piece, *strat))
		return (1);
	else if (ft_fill_side(board, piece, *strat))
		return (1);
	else if (ft_place_force(board, piece))
		return (1);
	sleep(8);
	ft_write_piece(0, 0);
	return (0);
}
