/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:03:16 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/22 11:22:03 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

t_size			ft_starting_side2(t_size play, t_size oppo)
{
	t_size		dir;

	if (oppo.x > play.x)
		dir.x = 1;
	if (play.x > oppo.x)
		dir.x = -1;
	if (play.x == oppo.x)
		dir.x = 0;
	if (oppo.y > play.y)
		dir.y = -1;
	if (play.y > oppo.y)
		dir.y = -1;
	if (play.y == oppo.y)
		dir.y = 0;
	return (dir);
}

t_size			ft_starting_side(t_elem board, int i, int j)
{
	t_size		play;
	t_size		oppo;

	while (++j < board.size.y)
	{
		i = -1;
		while (++i < board.size.x)
		{
			if (board.tab[j][i] == board.player ||
					board.tab[j][i] == ft_tolower(board.player))
			{
				play.x = i;
				play.y = j;
			}
			if (board.tab[j][i] == board.opponent ||
					board.tab[j][i] == ft_tolower(board.opponent))
			{
				oppo.x = i;
				oppo.y = j;
			}
		}
	}
	return (ft_starting_side2(play, oppo));
}

static void		ft_register(t_strat *strat, int x, int y)
{
	if (strat->highest.y < 0 || strat->highest.y > y)
	{
		strat->highest.y = y;
		strat->highest.x = x;
	}
	if (strat->lowest.y < 0 || strat->lowest.y < y)
	{
		strat->lowest.y = y;
		strat->lowest.x = x;
	}
	if (strat->rightest.x < 0 || strat->rightest.x < x)
	{
		strat->rightest.y = y;
		strat->rightest.x = x;
	}
	if (strat->leftest.x < 0 || strat->leftest.x > x)
	{
		strat->leftest.y = y;
		strat->leftest.x = x;
	}
}

static void		ft_register_op(t_strat *strat, int x, int y)
{
	if (strat->op_highest.y < 0 || strat->op_highest.y > y)
	{
		strat->op_highest.y = y;
		strat->op_highest.x = x;
	}
	if (strat->op_lowest.y < 0 || strat->op_lowest.y < y)
	{
		strat->op_lowest.y = y;
		strat->op_lowest.x = x;
	}
	if (strat->op_rightest.x < 0 || strat->op_rightest.x < x)
	{
		strat->op_rightest.y = y;
		strat->op_rightest.x = x;
	}
	if (strat->op_leftest.x < 0 || strat->op_leftest.x > x)
	{
		strat->op_leftest.y = y;
		strat->op_leftest.x = x;
	}
}

void			ft_analyse_board(t_elem board, t_strat *strat)
{
	int			x;
	int			y;

	y = 0;
	while (y < board.size.y)
	{
		x = 0;
		while (x < board.size.x)
		{
			if (board.tab[y][x] == board.player ||
					board.tab[y][x] == ft_tolower(board.player))
				ft_register(strat, x, y);
			else if (board.tab[y][x] == board.opponent ||
					board.tab[y][x] == ft_tolower(board.opponent))
				ft_register_op(strat, x, y);
			x++;
		}
		y++;
	}
}
