/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_n_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:05:59 by davioliv          #+#    #+#             */
/*   Updated: 2024/04/15 18:11:11 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	receive_errors(t_game *so_long, char *msg)
{
	ft_printf("%s\n", msg);
	quit_game(so_long);
	exit(EXIT_FAILURE);
}

int	exit_game(t_game *so_long)
{
	quit_game(so_long);
	exit(EXIT_SUCCESS);
}

/*void	flood_fill(t_game *so_long)
{*/
