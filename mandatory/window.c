/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:34:35 by irkalini          #+#    #+#             */
/*   Updated: 2024/08/29 13:13:05 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.line_count)
	{
		x = 0;
		while (x < game->map.len)
		{
			render_sprite(y, x, game);
			x++;
		}
		y++;
	}
	return (0);
}

void	render_sprite(int y, int x, t_game *game)
{
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->wall.xpm_ptr, x * game->wall.x, y * game->wall.y);
	else if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->space.xpm_ptr, x * game->space.x, y * game->space.y);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->collect.xpm_ptr, x * game->collect.x, y * game->collect.y);
	else if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->exit.xpm_ptr, x * game->exit.x, y * game->exit.y);
	else if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->player_f.xpm_ptr, x * game->player_f.x, y * game->player_f.y);
}

int	destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->space.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_f.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collect.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
	free_map(game->map.map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int	open_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.len * 120, \
	game->map.line_count * 120, "so_long");
	if (!game->win_ptr)
		return (free(game->mlx_ptr), 1);
	init_mlx_data(game);
	init_sprites(game);
	render_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keys, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, destroy, game);
	mlx_loop_hook(game->mlx_ptr, render_map, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
