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
	int		fd;
	char	*line;

	so_long->rows = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		receive_errors(so_long, "Error while opening map_file");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		so_long->rows++;
	}
	if (so_long->rows < 3)
		receive_errors(so_long, "Map too short");
}

void	read_map(t_game *so_long, int fd)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < so_long->rows)
	{
		line = get_next_line(fd);
		if (!line)
			receive_errors(so_long, "Couldn't read map");
		so_long->map[i] = ft_strtrim(line, "\n");
		if (!so_long->map)
			receive_errors(so_long, "Couldn't insert map");
		free(line);
	}
	so_long->cols = ft_strlen(so_long->map[0]);
	if (so_long->cols < 3 && so_long->rows < 5)
		receive_errors(so_long, "Map too thin");
}

void	make_map(t_game *so_long, char *map_file)
{
	int	fd;

	count_rows(so_long, map_file);
	so_long->map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!so_long->map)
		receive_errors(so_long, "ERROR\n Problem while making map");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		receive_errors(so_long, "Error while opening map_file");
	read_map(so_long, fd);
	close(fd);
}
