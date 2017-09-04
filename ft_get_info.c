/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 08:34:54 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/31 10:06:48 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

void	ft_get_player(t_elem *board)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
	{
		board->player = 'O';
		board->opponent = 'X';
	}
	else
	{
		board->player = 'X';
		board->opponent = 'O';
	}
	free(line);
}

void	ft_get_size(t_size *size)
{
	int		i;
	int		*target;
	char	*line;

	if (!(get_next_line(0, &line)))
		exit(0);
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
	free(line);
}

char	**ft_set_array(t_size size)
{
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
		free(line);
	}
	return (tab);
}

void	ft_free_tab(t_elem *elem)
{
	int		j;

	j = 0;
	while (j < elem->size.y)
	{
		free(elem->tab[j]);
		j++;
	}
	free(elem->tab);
}
