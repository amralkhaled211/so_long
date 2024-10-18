/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:46:40 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 18:17:15 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_left_wall(t_game *game);
static void	check_left(t_game *game);

void	move_left(t_game *game)
{
	check_left(game);
	game->player.mem = 2;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->player_l.ptr, game->player.x, game->player.y);
	return ;
}

static void	check_left(t_game *game)
{
	if (game->player.x > CHARACTER_SIZE)
	{
		if (!is_left_wall(game))
		{
			game->player.x -= CHARACTER_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_left_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[(game->player.y / CHARACTER_SIZE)] \
	[((game->player.x - CHARACTER_SIZE) / CHARACTER_SIZE)] != '1') \
	);
}
