/* ************************************************************************** */
/*									                                        */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:20:22 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 17:22:50 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->window_pointer, event, mask, f, game);
}

static void	init_game(t_game *game, char *path)
{
	in_the_map(game, path);
	init_window(game);
	init_images(game);
	render_map(game);
	init_hook(game, 2, 1L << 0, key_handler);
	init_hook(game, 17, 0, red_cross);
	init_hook(game, 12, 32768, mini_maker);
	mlx_loop(game->mlx_pointer);
}

static int	is_valid_file(char *path)
{
	char	*temp;

	temp = ft_strrchr(path, '.');
	if (temp)
	{
		if (ft_strcmp(temp, ".ber") == 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		endgame("Invalid, number of arguments", &game, 2);
	else if (argc == 2 && (!is_valid_file(argv[1])))
		endgame("Invalid, file is not a .ber file", &game, 2);
	else if (argc == 2 && (is_valid_file(argv[1])))
		init_game(&game, argv[1]);
	return (0);
}
