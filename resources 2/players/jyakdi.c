/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jyakdi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:34:11 by jyakdi            #+#    #+#             */
/*   Updated: 2017/04/26 15:23:11 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		main()
{
	char	*line;
	t_elem	board;
	t_elem	piece;

	ft_get_player(&board);
	ft_get_size(&board.size);
	get_next_line(0, &line);
	board.tab = ft_get_array(board.size, 4);
/*		int	i;
		int	j = 0;
		ft_putendl_fd("tab enregistree = ", 2);
		while (j < board.size.y)
		{
			i=  0;
			while (i < board.size.x)
			{
				ft_putchar_fd(board.tab[j][i], 2);
				i++;
			}
			ft_putendl_fd("", 2);
			j++;
		}
*/
	ft_get_size(&piece.size);
	piece.tab = ft_get_array(piece.size, 0);

/*		j = 0;
		ft_putendl_fd("piece enregistree = ", 2);
		while (j < piece.size.y)
		{
			i=  0;
			while (i < piece.size.x)
			{
				ft_putchar_fd(piece.tab[j][i], 2);
				i++;
			}
			j++;
		}*/
	ft_place(board, piece);
	while (get_next_line(0, &line))
	{
		get_next_line(0, &line);
		board.tab = ft_get_array(board.size, 4);
		ft_get_size(&piece.size);
		piece.tab = ft_get_array(piece.size, 0);

/*		ft_putendl_fd("piece enregistree = ", 2);
		while (j < piece.size.y)
		{
			i=  0;
			while (i < piece.size.x)
			{
				ft_putchar_fd(piece.tab[j][i], 2);
				i++;
			}
			j++;
		}*/
		ft_place(board, piece);
	}
	return (0);
}
