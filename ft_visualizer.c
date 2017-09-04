/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 08:54:30 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/31 09:26:05 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		ft_open_window(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, SIZEX, SIZEY, "Filler");
	return (1);
}

t_image	*ft_create_t_image(void)
{
	t_image	*image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	return (image);
}

t_all	*ft_create_t_all(void)
{
	t_all	*all;
	t_image	*image;
	t_elem	*board;
	t_elem	*piece;
	t_strat	*strat;

	if (!(all = ft_memalloc(sizeof(t_all))))
		return (NULL);
	if (!(board = ft_memalloc(sizeof(t_elem))))
		return (NULL);
	if (!(piece = ft_memalloc(sizeof(t_elem))))
		return (NULL);
	if (!(strat = ft_memalloc(sizeof(t_strat))))
		return (NULL);
	if (!(all->img = ft_create_t_image()))
		return (NULL);
	if (!(all->img_piece = ft_create_t_image()))
		return (NULL);
	all->board = board;
	all->piece = piece;
	all->strat = strat;
	all->nb = 0;
	all->end = 0;
	all->wait = 0;
	return (all);
}

int		ft_change_wait(t_all *all, int n)
{
	if (n == 1)
	{
		if (all->wait < 5)
			all->wait += 1;
		else
			return (-1);
	}
	else
	{
		if (all->wait > 0)
			all->wait -= 1;
		else
			return (-1);
	}
	return (1);
}

int		ft_key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_PLUS)
		ft_change_wait(all, 1);
	else if (keycode == KEY_MINUS)
		ft_change_wait(all, -1);
	return (0);
}
