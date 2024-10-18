/* ************************************************************************** */
/*									                                          */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:01:14 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 18:40:11 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define CHARACTER_SIZE	32

typedef struct s_element_num
{
	int	collecting;
	int	exit;
	int	empty;
	int	start;
	int	moves;

}	t_element_num;

typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	char	*line;

}	t_draw;

typedef struct s_imge
{
	void	*ptr;
	int		movements;
	int		mem;
	int		x;
	int		y;

}	t_imge;

typedef struct s_game
{
	void				*mlx_pointer;
	void				*window_pointer;
	t_draw				plot;
	t_imge				floor;
	t_imge				wall;
	t_imge				portal;
	t_imge				collect;
	t_imge				player;
	t_imge				player_l;
	t_imge				player_r;
	t_imge				player_u;
	t_element_num		i;

}	t_game;

typedef struct s_index
{
	int	x;
	int	y;

}	t_index;

void			free_the_map(t_game *game);
void			ft_destroy(t_game *game);
void			endgame(char *message, t_game *game, int i);
bool			is_surrounded_with_walls(t_game *game, int y, int x);
bool			is_rectangular(t_game *game);
bool			is_valid_character(t_game *game, int y, int x);
void			is_elements_num_valid(t_game *game,
					t_element_num *count, char *temp);
bool			is_two_line(char *str_map, int i);
int				ft_open_file(char *p);
t_element_num	ft_counter(void);
int				len_map_valid(char **map, t_game *game);
void			in_the_map(t_game *game, char *path);
void			render_map(t_game *game);
void			init_window(t_game *game);
void			init_images(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			move_up(t_game *game);
void			move_down(t_game *game);
int				mini_maker(t_game *game);
void			render_player(t_game *game);
int				key_handler(int keycode, t_game *game);
void			print_moves(t_game *game);
int				red_cross(t_game *game);
int				isolated(t_game *game);
void			count_element(t_element_num *count, char c);
#endif
