#include "so_long.h"

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}		t_mlx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_input(int keysym, t_mlx *lib)
{
	if (keysym == ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_display(lib->mlx);
		mlx_destroy_window(lib->mlx, lib->mlx_win);
		free(lib->mlx);
		exit(EXIT_SUCCESS);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}


int	main(void)
{
	int	x;
	int	y;
	t_data	img;
	t_mlx	lib;

	x = 0;
	y = 0;
	lib.mlx = mlx_init();
	if (!lib.mlx)
		ft_printf("ERROR");
	lib.mlx_win =  mlx_new_window(lib.mlx, 640, 480, "SALVE");
	if (!lib.mlx_win)
		ft_printf("ERROR");
	img.img = mlx_new_image(lib.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	while (x <= 640)
	{
		x++;
		while (y <= 480)
		{
			my_mlx_pixel_put(&img, x, y, create_trgb(0, 0, 0, 255));
			y++;
		}
		y = 0;
	}
	mlx_put_image_to_window(lib.mlx, lib.mlx_win, img.img, 0, 0);
	mlx_key_hook(lib.mlx_win, handle_input, &lib);
	mlx_loop(lib.mlx);
}
