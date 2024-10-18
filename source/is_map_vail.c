/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_vail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:31:40 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 17:47:37 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_surrounded_with_walls(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1') || \
		(game->plot.map[0][x] != '1') || (game->plot.map[y] \
		[game->plot.length - 1] != '1') || (game->plot.map[y][0] != '1'))
	{
		return (false);
	}
	return (true);
}

bool	is_rectangular(t_game *game)
{
	if (game->plot.height == game->plot.length)
	{
		return (false);
	}
	return (true);
}

bool	is_valid_character(t_game *game, int y, int x)
{
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
	{
		return (false);
	}
	return (true);
}

void	is_elements_num_valid(t_game *game, t_element_num *count, char *temp)
{
	if (!(count->collecting > 0 && count->exit == 1
			&& count->start == 1 && count->empty > 0))
	{
		free(temp);
		endgame("Invalid, elements!", game, 3);
	}
}

bool	is_two_line(char *string_map, int i)
{
	return ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])));
}
