/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:39:30 by irkalini          #+#    #+#             */
/*   Updated: 2024/08/29 13:11:47 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->map.player_x = x;
				game->map.player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.line_count || y >= game->map.len
		|| game->map.c_map[x][y] == '1' || game->map.c_map[x][y] == 'V')
		return ;
	if (game->map.c_map[x][y] == 'C')
		game->map.collect_found++;
	if (game->map.c_map[x][y] == 'E')
		game->map.exit_found = 1;
	game->map.c_map[x][y] = 'V';
	check_path(game, x + 1, y);
	check_path(game, x - 1, y);
	check_path(game, x, y + 1);
	check_path(game, x, y - 1);
}

void	init_c_map(t_game *game)
{
	int	i;

	i = 0;
	game->map.c_map = (char **)malloc(sizeof(char *) * \
	(game->map.line_count + 1));
	if (!game->map.c_map)
		return ;
	while (i < game->map.line_count)
	{
		game->map.c_map[i] = ft_strdup(game->map.map[i]);
		if (!game->map.c_map[i])
		{
			while (i > 0)
				free(game->map.c_map[--i]);
			free(game->map.c_map);
			game->map.c_map = NULL;
			return ;
		}
		i++;
	}
	game->map.c_map[i] = NULL;
	game->map.len = ft_strlen(game->map.c_map[0]);
}

char	**valid_map(t_game *game, char *map_file)
{
	game->map.map = read_map(game, map_file);
	if (game->map.map == NULL)
		return (NULL);
	if (check_rec_chars(game) == 0 || check_murs(game) == 0)
		return (free_map(game->map.map), NULL);
	if (check_comp(game) == 0)
		return (free_map(game->map.map), NULL);
	init_c_map(game);
	find_player(game);
	check_path(game, game->map.player_y, game->map.player_x);
	if (game->map.collect_found != game->map.collect || !game->map.exit_found)
	{
		free_map(game->map.c_map);
		free_map(game->map.map);
		return (ft_printf("Error\nInvalid map\n"), NULL);
	}
	free_map(game->map.c_map);
	return (game->map.map);
}
