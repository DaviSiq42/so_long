/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:18:47 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/05 12:10:00 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_new_line(char *line)
{
	if (line[0] == '\0')
	{
		free (line);
		line = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*c[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	c[fd] = read_line(fd, c[fd]);
	if (!c[fd])
		return (NULL);
	line = insert_line(c[fd]);
	c[fd] = reset_line(c[fd]);
	return (line);
}
