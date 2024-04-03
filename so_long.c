/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:50 by davioliv          #+#    #+#             */
/*   Updated: 2024/02/21 17:48:52 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(char *map)
{
	t_mlx	lib;
	
	start_mlx(&lib);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		game_init(argv[1]);
	else

	return (0);
}
