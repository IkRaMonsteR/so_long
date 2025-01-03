/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:51:25 by irkalini          #+#    #+#             */
/*   Updated: 2025/01/03 01:12:23 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	touch_enemy(t_game *game)
{
	ft_printf("YOU TOUCHED THE ENEMY AND LOST!\n");
	destroy(game);
}

void	move_and_anim(t_game *game)
{
	char	*moves;
	char	*string;

	moves = ft_itoa(game->move);
	string = ft_strjoin("Number of movements: ", moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 20, 10, 0x39FF14, string);
	free(moves);
	free(string);
}

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
	game->map.enemy = 0;
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
