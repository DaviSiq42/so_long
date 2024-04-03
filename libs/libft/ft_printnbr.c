/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:53:28 by davioliv          #+#    #+#             */
/*   Updated: 2024/03/05 17:56:45 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(int i)
{
	int	len;

	len = 0;
	if (i < 0)
	{
		i = i * -1;
		len = 1;
	}
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

int	ft_printnbr(int i)
{
	ft_putnbr_fd(i, 1);
	return (ft_nbr_len(i));
}

int	ft_printunbr(unsigned int i)
{
	int				len;
	unsigned int	t;

	len = 0;
	t = i;
	if (i > 10)
		ft_printunbr(i / 10);
	ft_putchar_fd(i % 10 + 48, 1);
	while (t > 0)
	{
		t = t / 10;
		len++;
	}
	return (len);
}
