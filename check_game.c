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
			else if (!ft_strchr("EPC10", so_long->map[l][c]))
				receive_errors(so_long, "Invalid characters on map");
		}
	}
}

int	check_walls(t_game *so_long)
{
	int	i;
	size_t	main_len;

	i = -1;
	main_len = ft_strlen(so_long->map[0]);
	while (++i < so_long->rows)
	{
		if (ft_strlen(so_long->map[i]) != main_len)
			return (EXIT_FAILURE);
	}
	so_long->cols = ft_strlen(so_long->map[0]);
	if (so_long->cols < 3 && so_long->rows < 5)
		receive_errors(so_long, "Map too thin");
	return (EXIT_SUCCESS);
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
	if (check_walls(so_long))
		receive_errors(so_long, "Invalid map format");
	if (check_surround(so_long))
		receive_errors(so_long, "Map not surrounded by walls.");
	check_locs(so_long);
	if (so_long->player != 1)
		receive_errors(so_long, "ERROR\nWrong number of players.");
	if (so_long->exit != 1)
		receive_errors(so_long, "ERROR\nWrong number of exits."); 
	if (so_long->total_coins < 1)
		receive_errors(so_long, "ERROR\nNo coins on the map.");
	if (check_path(so_long))
		receive_errors(so_long, "ERROR\nPlayer can't find all coins or exit.");
	return (0);
}
