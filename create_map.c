/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:12:22 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/05 15:11:34 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_rows(t_game *so_long, char *map_file)
{
	int	fd;
	char	*line;

	so_long->rows = 0;
	fd = open(map_file, O_RDONLY);
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

	i = -1;
	while (++i < so_long->rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		so_long->map[i] = ft_strtrim(line, "\n");
		free(line);
	}
	so_long->cols = ft_strlen(so_long->map[0]);
}

void	make_map(t_game *so_long, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	count_rows(so_long, map_file);
	so_long->map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!so_long->map)
		ft_printf("ERROR\n Problem while making map");
	read_map(so_long, fd);
	close(fd);
}
