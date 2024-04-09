/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:12 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/09 14:03:09 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 30 /*	later switch size to the number of pixels of sprite for player	*/

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

typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}		t_data;

typedef struct	s_coordinates {
	int	x;
	int	y;
}		t_coordinates;

typedef struct	s_game{
	t_data	img;
	t_coordinates	loc;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int	cols;
	int	rows;
}		t_game;

void	start_mlx(t_game *so_long);
void	game_init(char *map);
void	make_map(t_game *so_long, char *map_file);
int	clean_game(t_game *so_long);
int	handle_key(int key, t_game *so_long);

#endif
