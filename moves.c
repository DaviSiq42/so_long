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

void	check_move(t_game *so_long)
{
	if (so_long->map[so_long->curr.y][so_long->curr.x] != '1')
	{
		ft_printf("You moved %i times.\n", so_long->moves);
		so_long->map[so_long->curr.y][so_long->curr.x] = 'P';
		so_long->map[so_long->prev.y][so_long->prev.x] = '0';
		put_sprites(so_long, so_long->prev.y, so_long->prev.x);
		put_sprites(so_long, so_long->curr.y, so_long->curr.x);
	}
	else
	{
		so_long->curr.y = so_long->prev.y;
		so_long->curr.x = so_long->prev.x;
	}
}

int	handle_input(int key, t_game *so_long)
{
	so_long->prev.y = so_long->curr.y;
	so_long->prev.x = so_long->curr.x;
	if (key == ESC)
		quit_game(so_long);
	if (key == W || key == UP)
		so_long->curr.y--;
	if (key == A || key == LEFT)
		so_long->curr.x--;
	if (key == S || key == DOWN)
		so_long->curr.y++;
	if (key == D || key == RIGHT)
		so_long->curr.x++;
	check_move(so_long);
	return (0);
}


