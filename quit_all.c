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

void	clear_map(t_game *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i])
		free(so_long->map[i++]);
	free(so_long->map);
}

void	clear_test_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	clear_sprites(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		mlx_destroy_image(so_long->mlx, so_long->sprites[i].img);
	free(so_long->sprites);
}

void	quit_game(t_game *so_long)
{
	if (so_long->map)
		clear_map(so_long);
	if (so_long->sprites)
		clear_sprites(so_long);
	if (so_long->mlx_win)
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	if (so_long->mlx)
		mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
}
