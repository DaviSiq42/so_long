/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:07:30 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/03 15:42:37 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		ft_printf("ERROR\n Problem while initializing mlx");
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->cols * SIZE, so_long->rows * SIZE, "so_long");
	if (!so_long->mlx)
	{
		ft_printf("ERROR\n Problem while opening the window."); 
		return ;
	}
}

void	set_sprites(t_game *so_long)
{
	so_long->sprites = malloc(sizeof(t_sprite));
	if (!(so_long->sprites))
	{
		ft_printf("Couldn't allocate sprites");
		return ;
	}
	so_long->sprites->img = mlx_xpm_file_to_image(so_long->mlx, FW, &(so_long->sprites->width), &(so_long->sprites->height));
}

void	see_map(t_game *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < so_long->rows)
	{
		x = -1;
		while (++x < so_long->cols)
			put_sprites(so_long, x, y);
	}
}
void	put_sprites(t_game *so_long, int x, int y)
{
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->sprites->img, so_long->sprites->width * x, so_long->sprites->height * y);
}
