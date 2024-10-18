/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:53:11 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 18:27:40 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_element_handler(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->portal.x = x * CHARACTER_SIZE;
		game->portal.y = y * CHARACTER_SIZE;
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->portal.ptr, (x * CHARACTER_SIZE), (y * CHARACTER_SIZE));
	}
	else if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->wall.ptr, (x * CHARACTER_SIZE), (y * CHARACTER_SIZE));
	else if (game->plot.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->collect.ptr, (x * CHARACTER_SIZE), (y * CHARACTER_SIZE));
	}
	else
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, \
		game->floor.ptr, (x * CHARACTER_SIZE), (y * CHARACTER_SIZE));
}

static void	map_checker(t_game *game, int y, int x)
{
	if (!is_surrounded_with_walls(game, y, x))
		endgame("Invalid, map is not surrounded with walls", game, 4);
	else if (!is_rectangular(game))
		endgame("Invalid, map is not rectangular", game, 4);
	else if (!is_valid_character(game, y, x))
		endgame("Invalid, map contains invalid characters", game, 4);
	else if (!isolated(game))
		endgame("Invalid, map contains isolated elements", game, 4);
	map_element_handler(game, y, x);
	return ;
}

void	render_map(t_game *game)
{
	t_index	acord;

	acord.y = 0;
	while (game->plot.map[acord.y])
	{
		acord.x = 0;
		while (game->plot.map[acord.y][acord.x])
		{
			map_checker(game, acord.y, acord.x);
			acord.x++;
		}
		acord.y++;
	}
	return ;
}

void	render_player(t_game *game)
{
	t_index	point;

	point.y = 0;
	while (game->plot.map[point.y])
	{
		point.x = 0;
		while (game->plot.map[point.y][point.x])
		{
			if (game->plot.map[point.y][point.x] == 'P')
			{
				game->player.x = (CHARACTER_SIZE * point.x);
				game->player.y = (CHARACTER_SIZE * point.y);
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
					game->player.ptr, game->player.x, game->player.y);
				return ;
			}
			point.x++;
		}
		point.y++;
	}
	return ;
}

int	mini_maker(t_game *game)
{
	render_map(game);
	if (game->i.moves == 0)
		render_player(game);
	else if (game->player.mem == 1)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->player.ptr, game->player.x, game->player.y);
	else if (game->player.mem == 2)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->player_l.ptr, game->player.x, game->player.y);
	else if (game->player.mem == 3)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->player_r.ptr, game->player.x, game->player.y);
	else if (game->player.mem == 4)
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->player_u.ptr, game->player.x, game->player.y);
	return (0);
}
