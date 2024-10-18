/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:55 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 18:20:20 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_up_wall(t_game *game);
static void	check_up(t_game *game);

void	move_up(t_game *game)
{
	check_up(game);
	game->player.mem = 4;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->player_u.ptr, game->player.x, game->player.y);
	return ;
}

static void	check_up(t_game *game)
{
	if (game->player.y > CHARACTER_SIZE)
	{
		if (!is_up_wall(game))
		{
			game->player.y -= CHARACTER_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_up_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[((game->player.y - CHARACTER_SIZE) / CHARACTER_SIZE)]
			[(game->player.x / CHARACTER_SIZE)] != '1'));
}
