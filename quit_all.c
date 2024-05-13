/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:38:02 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/05 15:16:10 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(char **map)
{
	int	i;

	i = 0;
	while (map)
		free(map[i++]);
}

int	quit_game(t_game *so_long)
{
	mlx_destroy_display(so_long->mlx);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	clear_map(so_long->map);
	free(so_long->map);
	free(so_long->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
