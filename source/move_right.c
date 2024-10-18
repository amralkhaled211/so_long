/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:49:56 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 18:20:38 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_right_wall(t_game *game);
static void	check_right(t_game *game);

void	move_right(t_game *game)
{
	check_right(game);
	game->player.mem = 3;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->player_r.ptr, game->player.x, game->player.y);
	return ;
}

static void	check_right(t_game *game)
{
	if (game->player.x < \
	((game->plot.length * CHARACTER_SIZE) - (CHARACTER_SIZE * 2)))
	{
		if (!is_right_wall(game))
		{
			game->player.x += CHARACTER_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_right_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[(game->player.y / CHARACTER_SIZE)]
			[((game->player.x + CHARACTER_SIZE) / CHARACTER_SIZE)] != '1'));
}
