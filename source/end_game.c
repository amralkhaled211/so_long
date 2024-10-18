/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:09:34 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 20:22:48 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	mlx_destroy_image(game->mlx_pointer, game->portal.ptr);
	mlx_destroy_image(game->mlx_pointer, game->collect.ptr);
	mlx_destroy_image(game->mlx_pointer, game->player.ptr);
	mlx_destroy_image(game->mlx_pointer, game->player_l.ptr);
	mlx_destroy_image(game->mlx_pointer, game->player_r.ptr);
	mlx_destroy_image(game->mlx_pointer, game->player_u.ptr);
	mlx_destroy_window(game->mlx_pointer, game->window_pointer);
	mlx_destroy_display(game->mlx_pointer);
	free_the_map(game);
	free(game->mlx_pointer);
	return ;
}

void	free_the_map(t_game	*game)
{
	while (game->plot.height > 0)
	{
		free(game->plot.map[game->plot.height - 1]);
		game->plot.height--;
	}
	free(game->plot.map);
	return ;
}

void	endgame(char *message, t_game *game, int i)
{
	if (i == -1 || i == -1)
	{
		ft_printf("%s\n", message);
		ft_destroy(game);
		exit(0);
	}
	else if (i == 2)
	{
		ft_printf("Error\n%s\n", message);
		exit(1);
	}
	else if (i == 3)
	{
		ft_printf("Error\n%s\n", message);
		exit(1);
	}
	ft_printf("Error\n%s\n", message);
	ft_destroy(game);
	exit(1);
	return ;
}
