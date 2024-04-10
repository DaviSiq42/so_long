/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:44:07 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/05 16:29:00 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_game *so_long)
{
	if (key == ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", key);
		quit_game(so_long);
		return (0);
	}
	if (key == W)
	{
		ft_printf("The %d key (W) has been pressed\n\n", key);
		so_long->loc.y++;
		return (0);
	}
	ft_printf("The %d key has been pressed\n\n", key);
	return (0);
}
