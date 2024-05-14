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
void	receive_errors(t_game *so_long)
{
	if (check_map(so_long) == 11)
		ft_printf("ERROR\nWrong number of players.");
	if (check_map(so_long) == 22)
		ft_printf("ERROR\nWrong number of exits.");
	if (check_map(so_long) == 33)
		ft_printf("ERROR\nNo coins found on the map.");
	if (check_map(so_long) == 44)
		ft_printf("ERROR\nMap is not surrounded by walls.");
	exit(EXIT_FAILURE);
}

/*void	flood_fill(t_game *so_long)
{*/
