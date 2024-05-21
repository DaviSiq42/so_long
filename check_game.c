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

int	check_path(t_game *so_long)
{
	int	i;
	char	**test_map;
	int	path_checker;

	i = -1;
	path_checker = 0;
	test_map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!test_map)
		receive_errors(so_long, "Couldn't allocate test_map");
	while (++i < so_long->rows)
	{
		test_map[i] = ft_strdup(so_long->map[i]);
		if (!test_map)
			receive_errors(so_long, "Couldn't allocate map in test_map");
	}
	path_checker = flood_fill(so_long->total_coins, so_long->curr.x, so_long->curr.y, test_map);
	clear_test_map(test_map);
	return (path_checker);
}
	
void	check_locs(t_game *so_long)
{
	int	c;
	int	l;

	l = -1;
	while (++l < so_long->rows)
	{
		c = -1;
		while (++c < so_long->cols)
		{
			if (so_long->map[l][c] == 'P')
			{
				so_long->player++;
				so_long->curr.y = l;
				so_long->curr.x = c;
			}
			else if (so_long->map[l][c] == 'E')
				so_long->exit++;
			else if (so_long->map[l][c] == 'C')
				so_long->total_coins++;
		}
	}
}

int check_surround(t_game *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < so_long->rows)
	{
		if (so_long->map[y][0] != '1' || so_long->map[y][so_long->cols - 1] != '1')
			return (1);
	}
	x = -1;
	while (++x < so_long->cols)
	{
		if (so_long->map[so_long->rows - 1][x] != '1' || so_long->map[0][x] != '1')
			return (1);
	}
	return (0);
}

int	check_map(t_game *so_long)
{
	check_locs(so_long);
	if (so_long->player != 1)
		receive_errors(so_long, "ERROR\nWrong number of players.");
	if (so_long->exit != 1)
		receive_errors(so_long, "ERROR\nWrong number of exits."); 
	if (so_long->total_coins < 1)
		receive_errors(so_long, "ERROR\nNo coins on the map.");
	if (check_surround(so_long) == 1)
		receive_errors(so_long, "ERROR\nMap not surrounded by walls.");
	if (check_path(so_long))
		receive_errors(so_long, "ERROR\nPlayer can't find all coins or exit.");
	return (0);
}
