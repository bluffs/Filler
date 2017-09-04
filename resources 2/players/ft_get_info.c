/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 08:34:54 by jyakdi            #+#    #+#             */
/*   Updated: 2017/04/26 15:26:47 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

void	ft_get_player(t_elem *board)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strcmp(line, "$$$ exec p1 : [players/jyakdi.filler]") == 0)
	{
		board->player = 'O';
		board->opponent = 'X';
	}
	else if (ft_strcmp(line, "$$$ exec p2 : [players/jyakdi.filler]") == 0)
	{
		board->player = 'X';
		board->opponent = 'O';
	}
}

void	ft_get_size(t_size *size)
{
	int		i;
	int		*target;
	char	*line;

	get_next_line(0, &line);
	target = &size->y;
	i = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			*target = ft_atoi(&line[i]);
			target = &size->x;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		else
			i++;
	}
}

char	**ft_set_array(t_size size)
{
	char	*line;
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_memalloc(sizeof(tab) * (size.y + 1))))
		return (0);
	while (i < size.y)
	{
		if (!(tab[i] = ft_memalloc(sizeof(*tab) * (size.x + 1))))
			return (0);
		i++;
	}
	return (tab);
}

char	**ft_get_array(t_size size, int start)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = 0;
	tab = ft_set_array(size);
	while (i < size.y)
	{
		get_next_line(0, &line);
		j = start;
		while (j <= size.x + start)
		{
			tab[i][j - start] = line[j];
			j++;
		}
		i++;
	}
	return (tab);
}
