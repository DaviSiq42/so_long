/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:20:16 by davioliv          #+#    #+#             */
/*   Updated: 2024/05/13 14:10:58 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_locs(t_game *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < so_long->rows)
	{
		x = -1;
		while (++x < so_long->cols)
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->player++;
				so_long->curr.y = x;
				so_long->curr.x = y;
			}
			if (so_long->map[y][x] == 'E')
				so_long->exit++;
			if (so_long->map[y][x] == 'C')
				so_long->total_coins++;
		}
	}
}

int check_surround(t_game *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (y++ <= so_long->rows)
	{
		if (so_long->map[y][0] != '1' || so_long->map[y][so_long->rows] != '1')
			return (1);
	}
	x = -1;
	while (x++ <= so_long->cols)
	{
		if (so_long->map[so_long->cols][x] != '1' || so_long->map[0][x] != '1')
			return (1);
	}
	return (0);
}

int	check_map(t_game *so_long)
{
	check_locs(so_long);
	if (so_long->player != 1)
		return (11);
	if (so_long->exit != 1)
		return (22);
	if (so_long->total_coins < 1)
		return (33);
	if (check_surround(so_long) == 1)
		return (44);
	return (0);
}
