#include "so_long.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_lenght + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_input(int key, t_game *lib)
{
	if (key == ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", key);
		mlx_destroy_display(lib->mlx);
		mlx_destroy_window(lib->mlx, lib->mlx_win);
		free(lib->mlx);
		exit(EXIT_SUCCESS);
		return (0);
	}
	if (key == W)
	{
		ft_printf("The %d key (W) has been pressed\n\n", key);
		lib->loc.y++;
		player_init(lib->loc.x, lib->loc.y, lib);
		return (0);
	}
	ft_printf("The %d key has been pressed\n\n", key);
	return (0);
}

int	quit_game(t_game *lib)
{
	mlx_destroy_display(lib->mlx);
	mlx_destroy_window(lib->mlx, lib->mlx_win);
	free(lib->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	player_init(int x, int y, t_game *lib)
{
	while (x <= 50)
	{
		x++;
		while (y <= 400 && y >= 350)
		{
			my_mlx_pixel_put(lib, x, y, create_trgb(0, 0, 0, 255));
			y++;
		}
		y = 350;
	}
	mlx_put_image_to_window(lib->mlx, lib->mlx_win, lib->img.img, 0, 0);
}

int	main(void)
{
	t_game	lib;

	lib.loc.x = 0;
	lib.loc.y = 350;
	lib.mlx = mlx_init();
	if (!lib.mlx)
		ft_printf("ERROR");
	lib.mlx_win =  mlx_new_window(lib.mlx, 640, 480, "SALVE");
	if (!lib.mlx_win)
		ft_printf("ERROR");
	lib.img.img = mlx_new_image(lib.mlx, 640, 480);
	lib.img.addr = mlx_get_data_addr(lib.img.img, &lib.img.bits_per_pixel, &lib.img.line_lenght, &lib.img.endian);
	mlx_hook(lib.mlx_win, ON_KEYPRESS, (1L << 0), handle_input, &lib);
	mlx_hook(lib.mlx_win, ON_DESTROY, (1L << 17), quit_game, &lib); 
	player_init(lib.loc.x, lib.loc.y, &lib);
	mlx_loop(lib.mlx);
}
