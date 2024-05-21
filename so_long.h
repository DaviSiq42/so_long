/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:12 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/05 12:48:19 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 32
# define SPRITES 5

# define FW1 "sprites/wall.xpm"
# define FB1 "sprites/background.xpm"
# define FE1 "sprites/exit.xpm"
# define FC1 "sprites/coins.xpm"
# define FP1 "sprites/player.xpm"

# define W1 0
# define B1 1
# define E1 2
# define C1 3
# define P1 4

# define ON_KEYPRESS 2
# define ON_DESTROY 17

# define W	119
# define A	97
# define S	115
# define D	100
# define ESC	65307
# define LEFT	65361
# define RIGHT	65363
# define UP	65362
# define DOWN	65364

#include "libs/libft/libft.h"
#include "libs/mlx/mlx.h"

typedef enum e_mask
{
	KEYPRESS_MASK = (1L << 0),
	DESTROY_MASK = (1L << 17)
}	t_mask;

typedef struct s_sprite {
	void	*img;
	int	height;
	int	width;
}		t_sprite;

typedef struct	s_coordinates {
	int	x;
	int	y;
}		t_coordinates;

typedef struct	s_game{
	t_sprite	*sprites;
	t_coordinates	curr;
	t_coordinates	prev;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**test_map;
	int	exit;
	int	player;
	int	total_coins;
	int	coins;
	int	moves;
	int	cols;
	int	rows;
}		t_game;

//mlx.c
void	start_mlx(t_game *so_long);
void	set_sprites(t_game *so_long);
void	see_map(t_game *so_long);
void	put_sprites(t_game *so_long, int y, int x);
//so_long.c
void	game_init(char *map);
//create_map.c
void	count_rows(t_game *so_long, char *map_file);
void	read_map(t_game *so_long, int fd);
void	make_map(t_game *so_long, char *map_file);
//moves.c
int	handle_input(int key, t_game *so_long);
void	check_move(t_game *so_long);
void	ft_move(t_game *so_long);
//check_game.c
int	check_map(t_game *so_long);
int	check_path(t_game *so_long);
void	check_locs(t_game *so_long);
int	check_surround(t_game *so_long);
//quit_all.c
void	quit_game(t_game *so_long);
void	clear_map(t_game *so_long);
void	clear_test_map(char **map);
void	clear_sprites(t_game *so_long);
//flood_n_stuff.c
void	receive_errors(t_game *so_long, char *msg);
int	exit_game(t_game *so_long);
int	flood_fill(int total_coins, int x, int y, char **map);

#endif
