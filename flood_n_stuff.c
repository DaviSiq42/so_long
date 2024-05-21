/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_n_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:05:59 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/15 18:11:11 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	receive_errors(t_game *so_long, char *msg)
{
	ft_printf("%s\n", msg);
	quit_game(so_long);
	exit(EXIT_FAILURE);
}

int	exit_game(t_game *so_long)
{
	quit_game(so_long);
	exit(EXIT_SUCCESS);
}

int	flood_fill(int total_coins, int x, int y, char **map)
{
	static int	coins;
	static int	exit;

	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'E')
		exit++;
	if (map[y][x] == 'C')
		coins++;
	map[y][x] = '1';
	flood_fill(total_coins, x - 1, y, map);
	flood_fill(total_coins, x + 1, y, map);
	flood_fill(total_coins, x, y - 1, map);
	flood_fill(total_coins, x, y + 1, map);
	if (coins == total_coins && exit == 1)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
