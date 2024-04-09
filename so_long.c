/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:50 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/09 14:25:42 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(char *map)
{
	t_game	so_long;
	
	start_mlx(&so_long);
	make_map(&so_long, map);
	mlx_hook(so_long.mlx_win, ON_KEYPRESS, (1L << 0), handle_key, &so_long);
	mlx_hook(so_long.mlx_win, ON_DESTROY, (1L << 17), clean_game, &so_long);
	mlx_loop(so_long.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strnstr((argv[1]) + ft_strlen(argv[1]) - 4, ".ber", 4))
			game_init(argv[1]);
		else
			ft_printf("Invalid file extension! Try <map>.ber\n");
	}
	else
		ft_printf("Wrong number of arguments...\nInstead try: ./so_long <maps/_.ber>\n");
	return (0);
}
