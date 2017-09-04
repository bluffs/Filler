/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:32:33 by jyakdi            #+#    #+#             */
/*   Updated: 2017/04/26 16:01:47 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_analyse(t_elem board, t_size *highest, t_size *lowest)
{
	int		nb;
	int		x;
	int		y;


	nb = 0;
	y = 0;
	while (y < board.size.y)
	{
		x = 0;
		while (x < board.size.x)
		{
			if (board.tab[y][x] == board.player || board.tab[y][x] == board.player - 'A' + 'a')
				nb++;
			x++;
		}
		y++;
	}
	return (nb);
}

/*t_size	ft_find_highest(t_elem board, char play)
{
	int		y;
	int		x;
	t_size	highest;

	y = 0;
	while (y < board.size.y)
	{
		x = 0;
		while (x < board.size.x)
		{
			if (board.tab[y][x] == play || board.tab[y][x] == play - 'A' + 'a')
			{
				highest.y = y;
				highest.x = x;
				return (highest);
			}
			x++;
		}
		y++;
	}

	return (NULL);
}*/

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
			if ((y + j < 0 || x + i < 0 || y + j >= board.size.y || x + i >= board.size.x ) && piece.tab[j][i] == '*')
				return (0);
			else if (piece.tab[j][i] == '*' && (board.tab[y + j][x + i] == board.opponent || board.tab[y + j][x + i] == board.opponent - 'A' + 'a'))
				return (0);
			else if (y + j >= 0 && y + j < board.size.y && x + i >= 0 && x + i < board.size.x && piece.tab[j][i] == '*'
					&& (board.tab[y + j][x + i] == board.player || board.tab[y + j][x + i] == board.player - 'A' + 'a'))
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
				ft_printf("%d %d\n", y, x);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_place(t_elem board, t_elem piece)
{
	int		count;
	t_size	highest;
	t_size	lowest;

	//sleep(1);
	count = ft_analyse(board, &highest, &lowest);
	//up_left = ft_find_highest(board, player);
	//count = ft_count(player, board);
	/*if (place_up-side || place_down-side || place_side || place_force)
		return ;
	*/
	if (!(ft_place_force(board, piece)))
		ft_printf("0 0\n");
	//ft_putnbr_fd(count, 2);
	//ft_printf("8 2\n");
}
