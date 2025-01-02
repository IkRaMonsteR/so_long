/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:57:41 by irkalini          #+#    #+#             */
/*   Updated: 2024/08/29 16:27:40 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keys(int keysym, t_game *game)
{
	if (keysym == 119)
		move_player(game->map.player_y - 1, game->map.player_x, game, keysym);
	else if (keysym == 97)
		move_player(game->map.player_y, game->map.player_x - 1, game, keysym);
	else if (keysym == 100)
		move_player(game->map.player_y, game->map.player_x + 1, game, keysym);
	else if (keysym == 115)
		move_player(game->map.player_y + 1, game->map.player_x, game, keysym);
	else if (keysym == 65307)
		destroy(game);
	return (0);
}

void	move_player(int m_y, int m_x, t_game *game, int keysym)
{
	int			l_x;
	int			l_y;

	game->key = keysym;
	l_x = game->map.player_x;
	l_y = game->map.player_y;
	if (game->map.map[m_y][m_x] == 'T')
		touch_enemy(game);
	if (game->map.map[m_y][m_x] == 'E' && game->map.collect_found == 0)
		victory(game);
	else if (game->map.map[m_y][m_x] == 'C' || game->map.map[m_y][m_x] == '0')
	{
		game->map.map[l_y][l_x] = '0';
		if (game->map.map[m_y][m_x] == 'C')
			game->map.collect_found--;
		game->map.player_x = m_x;
		game->map.player_y = m_y;
		game->map.map[m_y][m_x] = 'P';
		game->move++;
		game->i_enemy *= -1;
		render_map(game);
	}
}

void	init_sprites(t_game *game)
{
	void	*ptr;

	ptr = game->mlx_ptr;
	game->wall = new_sprite(ptr, WALL_XPM);
	game->space = new_sprite(ptr, SPACE_XPM);
	game->collect = new_sprite(ptr, COLLECT_XPM);
	game->player_r = new_sprite(ptr, P_R_XPM);
	game->player_b = new_sprite(ptr, P_B_XPM);
	game->player_l = new_sprite(ptr, P_L_XPM);
	game->player_f = new_sprite(ptr, P_F_XPM);
	game->enemy_o = new_sprite(ptr, ENEMY_O_XPM);
	game->enemy_c = new_sprite(ptr, ENEMY_C_XPM);
	game->exit = new_sprite(ptr, EXIT_XPM);
}

t_img	new_sprite(void *ptr, char *path)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(ptr, path, &sprite.x, &sprite.y);
	if (!sprite.xpm_ptr)
	{
		ft_printf("Error\nFailed to load %s\n", path);
		exit(1);
	}
	return (sprite);
}

void	init_mlx_data(t_game *game)
{
	game->key = 115;
	game->i_enemy = 1;
	game->move = 0;
}
