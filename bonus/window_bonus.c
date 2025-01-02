/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:56:40 by irkalini          #+#    #+#             */
/*   Updated: 2024/08/29 16:31:35 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	move_and_anim(game);
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
		render_player(y, x, game);
	else if (game->map.map[y][x] == 'T' && game->i_enemy == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->enemy_o.xpm_ptr, x * game->enemy_o.x, y * game->enemy_o.y);
	else if (game->map.map[y][x] == 'T' && game->i_enemy == -1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->enemy_c.xpm_ptr, x * game->enemy_c.x, y * game->enemy_c.y);
}

void	render_player(int y, int x, t_game *game)
{
	if (game->key == 119)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->player_b.xpm_ptr, x * game->player_b.x, y * game->player_b.y);
	if (game->key == 97)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->player_l.xpm_ptr, x * game->player_l.x, y * game->player_l.y);
	if (game->key == 115)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->player_f.xpm_ptr, x * game->player_f.x, y * game->player_f.y);
	if (game->key == 100)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->player_r.xpm_ptr, x * game->player_r.x, y * game->player_r.y);
}

int	destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->space.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_r.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_l.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_f.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_b.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy_c.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy_o.xpm_ptr);
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
	mlx_hook(game->win_ptr, Expose, ExposureMask, render_map, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
