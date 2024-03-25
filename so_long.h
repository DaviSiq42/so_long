/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:12 by davioliv          #+#    #+#             */
/*   Updated: 2024/03/06 15:35:59 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ON_KEYPRESS 2

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

typedef struct	s_mlx{
	t_data	img;
	t_coordinates	loc;
	void	*mlx;
	void	*mlx_win;
}		t_mlx;

int	create_trgb(int t, int r, int g, int b);
void	player_init(int x, int y, t_mlx *lib);

#endif
