/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:17:24 by irkalini          #+#    #+#             */
/*   Updated: 2025/01/03 01:02:40 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid file extension\n");
		return (0);
	}
	return (1);
}

void	init_map_data(t_game *game)
{
	game->map.player = 0;
	game->map.player_x = 0;
	game->map.player_y = 0;
	game->map.exit = 0;
	game->map.exit_found = 0;
	game->map.collect = 0;
	game->map.collect_found = 0;
	game->map.fd = 0;
	game->map.line_count = 0;
	game->map.len = 0;
	game->map.map = NULL;
	game->map.c_map = NULL;
	game->map.line = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nInvalid input\n"), 1);
	if (!is_valid_extension(argv[1]))
		return (1);
	init_map_data(&game);
	game.map.map = valid_map(&game, argv[1]);
	if (!game.map.map)
		return (1);
	open_window(&game);
	return (0);
}
