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

void	ft_move(t_game *so_long)
{
	static int	c;

	if (c)
	{
		so_long->map[so_long->curr.y][so_long->curr.x] = 'P';
		so_long->map[so_long->prev.y][so_long->prev.x] = 'E';
		c = 0;
	}
	else if (so_long->map[so_long->curr.y][so_long->curr.x] == 'E')
	{
		so_long->map[so_long->curr.y][so_long->curr.x] = 'P';
		so_long->map[so_long->prev.y][so_long->prev.x] = '0';
		c = 1;
	}
	else
	{
		so_long->map[so_long->curr.y][so_long->curr.x] = 'P';
		so_long->map[so_long->prev.y][so_long->prev.x] = '0';
	}
	ft_printf("You moved %d times.\n", ++so_long->moves);
	put_sprites(so_long, so_long->prev.x, so_long->prev.y);
	put_sprites(so_long, so_long->curr.x, so_long->curr.y);
}

void	check_move(t_game *so_long, int key)
{
	if (key == ESC || key == W || key == UP || key == A
		|| key == LEFT || key == S || key == DOWN || key == D || key == RIGHT)
	{
		if (so_long->map[so_long->curr.y][so_long->curr.x] != '1')
		{
			if (so_long->map[so_long->curr.y][so_long->curr.x] == 'C')
				so_long->coins++;
			else if (so_long->map[so_long->curr.y][so_long->curr.x] == 'E')
			{
				if (so_long->coins == so_long->total_coins)
				{
					ft_printf("You won!\n");
					exit_game(so_long);
				}
			}
			ft_move(so_long);
		}
		else
		{
			so_long->curr.y = so_long->prev.y;
			so_long->curr.x = so_long->prev.x;
		}
	}
	return ;
}

int	handle_input(int key, t_game *so_long)
{
	so_long->prev.y = so_long->curr.y;
	so_long->prev.x = so_long->curr.x;
	if (key == ESC)
		exit_game(so_long);
	else if (key == W || key == UP)
		so_long->curr.y--;
	else if (key == A || key == LEFT)
		so_long->curr.x--;
	else if (key == S || key == DOWN)
		so_long->curr.y++;
	else if (key == D || key == RIGHT)
		so_long->curr.x++;
	check_move(so_long, key);
	return (0);
}
