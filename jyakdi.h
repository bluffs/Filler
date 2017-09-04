/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jyakdi.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 08:27:37 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/31 08:59:26 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __JYAKDI_H
# define __JYAKDI_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

# define SIZEX 1600
# define SIZEY 900
# define BOARD_SIZEX 1200
# define BOARD_SIZEY 900
# define PIECE_SIZEX 300
# define PIECE_SIZEY 300
# define TURN_SIZEY 200
# define KEY_PLUS 69
# define KEY_MINUS 78

typedef struct	s_image
{
	void			*image;
	unsigned char	*array;
	int				endian;
	int				sl;
	int				bpp;
}				t_image;

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct	s_elem
{
	char		player;
	char		opponent;
	t_size		size;
	char		**tab;
}				t_elem;

typedef struct	s_strat
{
	t_size		dir;
	t_size		highest;
	t_size		lowest;
	t_size		rightest;
	t_size		leftest;
	t_size		op_highest;
	t_size		op_lowest;
	t_size		op_rightest;
	t_size		op_leftest;

}				t_strat;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_image		*img_piece;
	t_elem		*board;
	t_elem		*piece;
	t_strat		*strat;
	int			nb;
	int			end;
	int			wait;
}				t_all;

void			ft_get_player(t_elem *board);
void			ft_free_tab(t_elem *elem);
char			**ft_get_array(t_size size, int start);
void			ft_get_size(t_size *size);
t_strat			ft_create_strat(t_elem board);
int				ft_turn(t_all *all);
int				ft_place(t_elem board, t_elem piece, t_strat *strat);
void			ft_analyse_board(t_elem board, t_strat *strat);
int				ft_place_up(t_elem board, t_elem piece, t_strat strat);
int				ft_place_down(t_elem board, t_elem piece, t_strat strat);
int				ft_place_side(t_elem board, t_elem piece, t_strat strat);
int				ft_fill_side(t_elem board, t_elem piece, t_strat strat);
int				ft_trypiece(t_elem board, t_elem piece, int y, int x);
int				ft_skip(void);
void			ft_write_piece(int y, int x);
t_all			*ft_create_t_all(void);
int				ft_open_window(t_all *all);
void			ft_open_image(t_all *all);
void			ft_draw_board(t_all *all);
void			ft_draw_border(t_image *img, int size_x, int size_y);
void			ft_draw_hor(t_image *img, int y, int size_x, int size_y);
void			ft_draw_ver(t_image *img, int x, int size_x, int size_y);
void			ft_draw_piece(t_all *all);
void			ft_fill_board(t_all *all);
void			ft_fill_piece(t_all *all);
int				ft_key_hook(int keycode, t_all *all);
t_size			ft_starting_side(t_elem board, int i, int j);
int				ft_print_turns(t_all *all);

#endif
