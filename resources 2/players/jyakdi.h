/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jyakdi.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 08:27:37 by jyakdi            #+#    #+#             */
/*   Updated: 2017/04/26 15:23:43 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __JYAKDI_H
#define __JYAKDI_H

#include "ft_printf_git2/ft_printf.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct	s_elem
{
	char	player;
	char	opponent;
	t_size	size;
	char	**tab;
}				t_elem;

void	ft_get_player(t_elem *board);
char	**ft_get_array(t_size size, int start);
void	ft_get_size(t_size *size);
void	ft_place(t_elem board, t_elem piece);

#endif
