/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:40 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/07 22:08:36 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_element_num	element_counter(char *temp, t_game *game)
{
	t_element_num	count;
	int				i;

	count = ft_counter();
	i = 0;
	while (temp[i] != '\0')
	{
		if (is_two_line(temp, i))
		{
			free(temp);
			endgame("There is double_line", game, 3);
		}
		count_element(&count, temp[i]);
		i++;
	}
	is_elements_num_valid(game, &count, temp);
	return (count);
}

static void	read_map(t_game *game, int fd)
{
	char	*temp;

	temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		temp = ft_strjoin_g(temp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->i = element_counter(temp, game);
	game->plot.map = ft_split(temp, '\n');
	if (game->plot.map == NULL)
	{
		free(temp);
		free(game->plot.map);
		endgame("Malloc failed", game, 2);
	}
	free(temp);
}

static void	lin_valid(char **map, t_game *game)
{
	int		i;
	t_index	ind;

	i = 0;
	ind.x = 0;
	ind.y = ft_strlen(map[0]);
	while (map[i])
	{
		ind.x = ft_strlen(map[i]);
		if (ind.x != ind.y)
		{
			free_the_map(game);
			endgame("lines are not the same size!", game, 2);
		}
		i++;
	}
}

int	len_map_valid(char **map, t_game *game)
{
	lin_valid(map, game);
	return (ft_strlen(map[0]));
}

void	in_the_map(t_game *game, char *path)
{
	int	fd;

	fd = ft_open_file(path);
	if (fd == -1)
		endgame("Invalid, file does not exist", game, 2);
	read_map(game, fd);
	game->plot.length = len_map_valid(game->plot.map, game);
	close(fd);
	return ;
}
