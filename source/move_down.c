/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:39:46 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/05 12:09:12 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_down_wall(t_game *game);
static void	check_down(t_game *game);

void	move_down(t_game *game)
{
	check_down(game);
	game->player.mem = 1;
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->player.ptr, game->player.x, game->player.y);
	return ;
}

static void	check_down(t_game *game)
{
	if (game->player.y < \
	((game->plot.height * CHARACTER_SIZE) - (CHARACTER_SIZE * 2)))
	{
		if (!is_down_wall(game))
		{
			game->player.y += CHARACTER_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_down_wall(t_game *game)
{
	return (! \
	(game->plot.map \
	[((game->player.y + CHARACTER_SIZE) / CHARACTER_SIZE)]
			[(game->player.x / CHARACTER_SIZE)] != '1')
	);
}
