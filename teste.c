#include "so_long.h"

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	x;
	int	y;
	t_data	img;

	x = 0;
	y = 0;
	mlx = mlx_init();
	if (!mlx)
		ft_printf("ERROR");
	mlx_win =  mlx_new_window(mlx, 640, 480, "SALVE");
	if (!mlx_win)
		ft_printf("ERROR");
	img.img = mlx_new_image(mlx, 640, 480);
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	ft_printf("%i\n", create_trgb(0, 0, 0, 255));
	mlx_loop(mlx);
}
