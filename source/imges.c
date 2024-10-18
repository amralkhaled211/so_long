/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:46:02 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/07 20:47:26 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->mlx_pointer = mlx_init();
	if (game->mlx_pointer == NULL)
	{
		free_the_map(game);
		exit(1);
	}
	game->window_pointer = mlx_new_window(game->mlx_pointer, \
		(game->plot.length * CHARACTER_SIZE), (game->plot.height
				* CHARACTER_SIZE), "so_long");
	if (game->window_pointer == NULL)
	{
		mlx_destroy_display(game->mlx_pointer);
		free_the_map(game);
		exit(1);
	}
}

void	init_images(t_game *game)
{
	game->wall.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/wall.xpm", &game->wall.x, &game->wall.y);
	game->floor.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/floor.xpm", &game->floor.x, &game->floor.y);
	game->collect.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/col.xpm", &game->collect.x, &game->collect.y);
	game->portal.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/exit.xpm", &game->portal.x, &game->portal.y);
	game->player.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/front.xpm", &game->player.x, &game->player.y);
	game->player_l.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/left.xpm", &game->player_l.x, &game->player_l.y);
	game->player_r.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/right.xpm", &game->player_r.x, &game->player_r.y);
	game->player_u.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/back.xpm", &game->player_u.x, &game->player_u.y);
}
