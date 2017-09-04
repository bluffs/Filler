/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jyakdi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:34:11 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/23 09:56:37 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jyakdi.h"

int		main(void)
{
	t_all	*all;

	if (!(all = ft_create_t_all()))
		return (-1);
	if (!(ft_open_window(all)))
		return (-1);
	mlx_loop_hook(all->mlx, ft_turn, all);
	mlx_hook(all->win, 2, 0, ft_key_hook, all);
	mlx_loop(all->mlx);
	return (0);
}
