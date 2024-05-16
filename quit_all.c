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
	while (so_long->map)
		free(so_long->map[i++]);
	free(so_long->map);
}

void	clear_sprites(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i <= SPRITES)
		mlx_destroy_image(so_long->mlx, so_long->sprites[i].img);	
	free(so_long->sprites);	
}

int	quit_game(t_game *so_long)
{
	clear_map(so_long);
	clear_sprites(so_long);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	return (0);
}
