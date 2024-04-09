/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:09 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/09 14:07:41 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_game *so_long)
{
	if (key == ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", key);
		mlx_destroy_display(so_long->mlx);
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
		free(so_long->mlx);
		exit(EXIT_SUCCESS);
	}
	if (key == W)
	{
		ft_printf("The %d key (W) has been pressed\n\n", key);
		so_long->loc.y++;
	}
	ft_printf("The %d key has been pressed\n\n", key);
	return (0);
}
