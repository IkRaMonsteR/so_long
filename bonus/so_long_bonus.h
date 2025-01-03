/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:55:42 by irkalini          #+#    #+#             */
/*   Updated: 2025/01/03 01:11:48 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include "../librairies/get_next_line/get_next_line.h"
# include "../librairies/ft_printf/ft_printf.h"
# include "../librairies/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL_XPM		"./../assets/asteroid_1.0.xpm"
# define SPACE_XPM		"./../assets/cosmos_1.0.xpm"
# define COLLECT_XPM	"./../assets/spacedonat_1.1.xpm"
# define P_L_XPM		"./../assets/P_LF.xpm"
# define P_R_XPM		"./../assets/P_RT.xpm"
# define P_F_XPM		"./../assets/P_FR.xpm"
# define P_B_XPM		"./../assets/P_BC.xpm"
# define EXIT_XPM		"./../assets/spaceship_1.1.xpm"
# define ENEMY_O_XPM	"./../assets/mnstr_open.xpm"
# define ENEMY_C_XPM	"./../assets/mnstr_close.xpm"

typedef struct s_map
{
	char	**map;
	char	**c_map;
	char	*line;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	int		exit_found;
	int		collect;
	int		collect_found;
	int		enemy;
	int		fd;
	int		line_count;
	int		len;
}	t_map;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		key;
	int		i_enemy;
	int		move;
	t_img	wall;
	t_img	space;
	t_img	player_r;
	t_img	player_l;
	t_img	player_b;
	t_img	player_f;
	t_img	collect;
	t_img	exit;
	t_img	enemy_o;
	t_img	enemy_c;
	t_map	map;
}	t_game;

int		count_lines(t_game *game, char *map_file);
char	**read_map(t_game *game, char *map_file);
int		check_rec_chars(t_game *game);
int		check_murs(t_game *game);
int		check_comp(t_game *game);
void	free_map(char **map);
void	find_player(t_game *game);
void	check_path(t_game *game, int x, int y);
void	init_c_map(t_game *game);
char	**valid_map(t_game *game, char *map_file);
int		handle_keys(int keysym, t_game *game);
void	move_player(int m_y, int m_x, t_game *game, int keysym);
void	init_sprites(t_game *game);
t_img	new_sprite(void *ptr, char *path);
void	init_map_data(t_game *game);
void	init_mlx_data(t_game *game);
int		render_map(t_game *game);
void	render_sprite(int y, int x, t_game *game);
int		destroy(t_game *game);
int		open_window(t_game *game);
int		is_valid_extension(char *filename);
void	render_player(int y, int x, t_game *game);
void	touch_enemy(t_game *game);
void	move_and_anim(t_game *game);
void	victory(t_game *game);

#endif
