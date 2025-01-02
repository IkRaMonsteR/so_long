/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:12:33 by irkalini          #+#    #+#             */
/*   Updated: 2024/08/23 11:37:07 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(t_game *game, char *map_file)
{
	int		count;

	count = 0;
	game->map.fd = open(map_file, O_RDONLY);
	if (game->map.fd < 0)
	{
		perror("Failed to open file or empty");
		return (-1);
	}
	game->map.line = get_next_line(game->map.fd);
	if (!game->map.line)
	{
		ft_printf("Error\nThe file is empty\n");
		return (close(game->map.fd), -1);
	}
	while (game->map.line != NULL)
	{
		count++;
		free(game->map.line);
		game->map.line = get_next_line(game->map.fd);
	}
	close(game->map.fd);
	return (count);
}

char	**read_map(t_game *game, char *map_file)
{
	int		i;

	i = 0;
	game->map.line_count = count_lines(game, map_file);
	if (game->map.line_count <= 0)
		return (NULL);
	game->map.map = (char **)malloc(sizeof(char *) * \
	(game->map.line_count + 1));
	if (!game->map.map)
		return (close(game->map.fd), NULL);
	game->map.fd = open(map_file, O_RDONLY);
	i = 0;
	game->map.line = get_next_line(game->map.fd);
	while (game->map.line != NULL)
	{
		game->map.map[i] = game->map.line;
		game->map.map[i][ft_strlen(game->map.line) - 1] = '\0';
		i++;
		game->map.line = get_next_line(game->map.fd);
	}
	game->map.map[i] = NULL;
	close(game->map.fd);
	return (game->map.map);
}

int	check_rec_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i] && game->map.map[i + 1])
	{
		if (ft_strlen(game->map.map[i]) != ft_strlen(game->map.map[i + 1]))
			return (ft_printf("Error\nMap is not rectangular\n"), 0);
		i++;
	}
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] != 'P' && game->map.map[i][j] != 'C' &&
			game->map.map[i][j] != 'E' && game->map.map[i][j] != '1' &&
			game->map.map[i][j] != '0')
				return (ft_printf("Error\nInvalid chars in map\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_murs(t_game *game)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(game->map.map[0]);
	j = 0;
	while (j < len)
	{
		if (game->map.map[0][j] != '1' ||
		game->map.map[game->map.line_count - 1][j] != '1')
			return (ft_printf("Error\nUp or down walls KO at %d col\n", j), 0);
		j++;
	}
	i = 1;
	while (i < game->map.line_count - 1)
	{
		if (game->map.map[i][0] != '1' ||
		game->map.map[i][ft_strlen(game->map.map[i]) - 1] != '1')
			return (ft_printf("Error\nMiddle walls KO at %d row\n", i), 0);
		i++;
	}
	return (1);
}

int	check_comp(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] != '\0')
		{
			if (game->map.map[i][j] == 'P')
				game->map.player++;
			else if (game->map.map[i][j] == 'E')
				game->map.exit++;
			else if (game->map.map[i][j] == 'C')
				game->map.collect++;
			j++;
		}
		i++;
	}
	if (game->map.player != 1 || game->map.exit != 1 || game->map.collect < 1)
		return (ft_printf("Error\nBad combination of components\n"), 0);
	return (1);
}
