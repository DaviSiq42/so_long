/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:53:31 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/09 14:04:28 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_game(t_game *so_long)
{
	mlx_destroy_display(so_long->mlx);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	free(so_long->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}	
