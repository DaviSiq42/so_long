/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:50 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/03 16:41:57 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(char *map)
{
	t_game	so_long;
	
	start_mlx(&so_long);
	make_map(&so_long, map);
	mlx_loop(so_long.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		game_init(argv[1]);
	else

	return (0);
}
