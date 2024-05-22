/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:50 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/15 18:04:24 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(char *map)
{
	t_game	so_long;

	ft_bzero(&so_long, sizeof(t_game));
	make_map(&so_long, map);
	check_map(&so_long);
	start_mlx(&so_long);
	set_sprites(&so_long);
	see_map(&so_long);
	mlx_hook(so_long.mlx_win, ON_KEYPRESS, KEYPRESS_MASK, handle_input, &so_long);
	mlx_hook(so_long.mlx_win, ON_DESTROY, DESTROY_MASK, exit_game, &so_long);
	mlx_loop(so_long.mlx);
}

int	check_ext(char *argv)
{
	char	*ext;

	ext = ft_substr(argv, ft_strlen(argv) - 4, 4);
	if (!ft_strncmp(ext, ".ber", 4))
	{
		free(ext);
		return (EXIT_SUCCESS);
	}
	else
	{
		free(ext);
		return (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_ext(argv[1]))
			ft_printf("Extension not recognized... Try <file>.ber\n");
		else
			game_init(argv[1]);
	}
	else
		ft_printf("Wrong number of arguments... Try type ./so_long <file>.ber\n");
	return (0);
}
