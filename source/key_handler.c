/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:52:35 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 17:48:12 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *game)
{
	game->player.mem = 0;
	if (keycode == ESC)
		endgame("", game, -1);
	else if (keycode == LEFT)
		move_left(game);
	else if (keycode == RIGHT)
		move_right(game);
	else if (keycode == UP)
		move_up(game);
	else if (keycode == DOWN)
		move_down(game);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.moves += 1;
	if (game->plot.map[game->player.y / CHARACTER_SIZE] \
	[game->player.x / CHARACTER_SIZE] == 'C')
	{
		game->plot.map[game->player.y / CHARACTER_SIZE] \
		[game->player.x / CHARACTER_SIZE] = '0';
		game->i.collecting--;
	}
	else if (game->plot.map[game->player.y / CHARACTER_SIZE]
		[game->player.x / CHARACTER_SIZE] == 'E' && game->i.collecting == 0)
	{
		endgame("\n\nThe End! :)", game, -1);
	}
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->i.moves, 1);
	return ;
}

int	red_cross(t_game *game)
{
	endgame("", game, -1);
	return (0);
}
