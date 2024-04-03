/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:07:30 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/03 15:42:37 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		ft_printf("ERROR");
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->cols * SIZE, so_long->rows * SIZE, "so_long");
	if (!so_long->mlx)
		ft_printf("ERROR\n Problem while opening the window."); 
}
