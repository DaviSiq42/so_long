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

void	flood_fill(t_game *so_long)
{
	char **test_map;
	int	i;

	test_map = ft_calloc(so_long->rows + 1, sizeof(char *));
	i = 0;
	if (!test_map)
		receive_errors(so_long, "Error allocating test_map");
	test_map = so_long->map;
	while (test_map[i])
		ft_printf("%s\n", test_map[i++]);
}
