/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:50 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/05 16:22:39 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(char *map)
{
	t_game	so_long;
	int	i;
	
	i = 0;
	make_map(&so_long, map);
	start_mlx(&so_long);
	mlx_hook(so_long.mlx_win, ON_KEYPRESS, (1L << 0), handle_input, &so_long);
	mlx_hook(so_long.mlx_win, ON_DESTROY, (1L << 17), quit_game, &so_long);
	while (so_long.map[i])
	{
		ft_printf("%s\n", so_long.map[i]);
		i++;
	}
	mlx_loop(so_long.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		game_init(argv[1]);
	else
		ft_printf("Wrong number of arguments... Try type ./so_long <file>.ber\n");
	return (0);
}
