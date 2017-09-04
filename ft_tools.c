/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:02:30 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/31 09:57:25 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_skip(void)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) == 1)
	{
		if (line)
			free(line);
		return (1);
	}
	return (0);
}

int		ft_other_turn(t_elem *board, t_elem *piece, t_strat *strat, t_all *all)
{
	if (ft_skip())
	{
		ft_skip();
		ft_free_tab(board);
		board->tab = ft_get_array(board->size, 4);
		ft_free_tab(piece);
		ft_get_size(&piece->size);
		piece->tab = ft_get_array(piece->size, 0);
		ft_fill_board(all);
		ft_draw_piece(all);
		if (!(ft_place(*board, *piece, strat)))
			all->end = 1;
	}
	return (1);
}

int		ft_first_turn(t_elem *board, t_elem *piece, t_strat *strat, t_all *all)
{
	ft_get_player(board);
	ft_get_size(&board->size);
	ft_skip();
	board->tab = ft_get_array(board->size, 4);
	ft_get_size(&piece->size);
	piece->tab = ft_get_array(piece->size, 0);
	*strat = ft_create_strat(*board);
	ft_open_image(all);
	ft_draw_board(all);
	ft_fill_board(all);
	ft_draw_piece(all);
	if (!(ft_place(*board, *piece, strat)))
		all->end = 1;
	return (1);
}

int		ft_turn(t_all *all)
{
	if (all->end)
		exit(0);
	if (all->nb == 0)
		ft_first_turn(all->board, all->piece, all->strat, all);
	else
	{
		mlx_destroy_image(all->mlx, all->img_piece->image);
		ft_other_turn(all->board, all->piece, all->strat, all);
	}
	all->nb += 1;
	return (1);
}

t_strat	ft_create_strat(t_elem board)
{
	t_strat		strat;

	strat.highest.x = -1;
	strat.highest.y = -1;
	strat.lowest.x = -1;
	strat.lowest.y = -1;
	strat.rightest.x = -1;
	strat.rightest.y = -1;
	strat.leftest.x = -1;
	strat.leftest.y = -1;
	strat.op_highest.x = -1;
	strat.op_highest.y = -1;
	strat.op_lowest.x = -1;
	strat.op_lowest.y = -1;
	strat.op_rightest.x = -1;
	strat.op_rightest.y = -1;
	strat.op_leftest.x = -1;
	strat.op_leftest.y = -1;
	strat.dir = ft_starting_side(board, -1, -1);
	return (strat);
}
