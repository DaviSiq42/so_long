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

typedef struct s_map
{
	
	
} t_map;

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

#endif
