/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:12:22 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/03 16:09:28 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_rows(t_game *so_long, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		so_long->rows++;
	}
}

void	read_map(t_game *so_long, int fd)
{
	char	*line;
	int	i;

	i = 0;
	while (i++ < so_long->rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		so_long->map[i] = line;
		free(line);
	}
	so_long->cols = ft_strlen(so_long->map[0]);
}

void	make_map(t_game *so_long, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	count_rows(&so_long, fd);
	so_long->map = ft_calloc(so_long->rows, sizeof(char *));
	if (!so_long->map)
		ft_printf("ERROR\n Problem while making map");
	read_map(&so_long, fd);
}
